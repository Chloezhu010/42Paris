#include "bigint.hpp"

//================================
// Constructors
//================================

bigint::bigint(): value("0"){}

bigint::bigint(unsigned int num)
{
    if (num == 0)
        value = "0";
    while (num != 0) {
        value += "0123456789"[num % 10]; // append least significant digit
        num /= 10;
    }
    // std::reverse(value.begin(), value.end()); // reverse to the correct order
}

bigint::bigint(const std::string& str)
{
    value = std::string(str.rbegin(), str.rend());
    remove_leading_zero();
}

bigint::bigint(const bigint& other)
{
    value = other.value;
}

//================================
// Assignment Operator
//================================

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other){
        value = other.value;
    }
    return *this;
}

//================================
// Destructor
//================================

bigint::~bigint(){}

//================================
// Addition Operators
//================================

/* modify this bigint by adding other to it */
bigint& bigint::operator+=(const bigint& other){
    int carry = 0; // hold the overflow when sum >= 10
    size_t max_len = std::max(value.size(), other.value.size()); // need to process at least this many digits

    // loop when there are still digits to process or there is a carry
    for (size_t i = 0; i < max_len || carry; i++){
        // extend value by adding leading 0 if needed
        if (i >= value.size()){
            value += '0';
        }
        // convert char to int digit
        int digit_a = value[i] - '0';
        int digit_b;
        if (i < other.value.size()){
            digit_b = other.value[i] - '0';
        } else
            digit_b = 0;
        // sum the digits and carry
        int sum = digit_a + digit_b + carry;
        value[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    remove_leading_zero();
    return *this;
}

/* add two bigints and return the new result 
    - doesn't modify the original bigints
*/ 
bigint bigint::operator+(const bigint& other) const {
    bigint result(*this); // copy current bigint
    result += other; // reuse the += operator
    return result;
}

//================================
// Increment Operators
//================================

/* prefix increment: ++a
    - increment this bigint by 1 and return the modified object
*/
bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

/* postfix increment: a++
    - increment this bigint by 1 but return the original object
*/
bigint bigint::operator++(int){
    bigint original(*this); // copy original value
    *this += bigint(1);
    return original; // return original value
}

//================================
// Comparison Operators
//================================

bool bigint::operator==(const bigint& other) const {
    return value == other.value;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
    // if different length, shorter is smaller
    if (value.size() != other.value.size()){
        return value.size() < other.value.size();
    }
    // same length, compare digit by digit from the right
    for (int i = value.size() - 1; i >= 0; i--){
        if (value[i] != other.value[i]){
            return value[i] < other.value[i];
        }
    }
    // all digits are the same
    return false;
}

bool bigint::operator>(const bigint& other) const {
    // euqal case
    if (*this == other)
        return false;
    // not equal case
    return !(*this < other);
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

//================================
// Shift Operators
//================================

/* modify this value */
bigint& bigint::operator<<=(unsigned int shift) {
    // special case 0 << n = 0
    if (value == "0")
        return *this;
    // add '0's at the beginning
    value.insert(0, shift, '0'); // pos, number of '0', char '0'
    return *this;
}

bigint bigint::operator<<(unsigned int shift) const {
    bigint result(*this);
    result <<= shift;
    return result;
}

bigint& bigint::operator>>=(unsigned int shift) {
    // if shift >= size, result is 0, eg. 123 >> 3
    if (shift >= value.size())
        value = "0";
    else { // remove the first n chars
        value.erase(0, shift); // pos, number of chars to erase
    }
    remove_leading_zero();
    return *this;
}

bigint bigint::operator>>(unsigned int shift) const{
    bigint result(*this);
    result >>= shift;
    return result;
}

//================================
// Substraction Operators
//================================

bigint& bigint::operator-=(const bigint& other) {
    // avoid negative result
    if (*this <= other) {
        value = "0";
        return *this;
    }
    int borrow = 0; // hold the borrow when digit_a < digit_b
    // subtract digit by digit
    for (size_t i = 0; i < value.size(); i++){
        int digit_a = value[i] - '0';
        int digit_b = (i < other.value.size()) ? (other.value[i] - '0') : 0;
        // perform subtraction with borrow
        int diff = digit_a - digit_b - borrow;
        if (diff < 0){
            diff += 10; // borrow from next digit
            borrow = 1; // set borrow for next iteration
        } else
            borrow = 0;
        value[i] = diff + '0';
    }
    remove_leading_zero();
    return *this;
}

bigint bigint::operator-(const bigint& other) const {        
    bigint result(*this);
    result -= other;
    return result;
}

//================================
// Getters 
//================================

// return internal representation, in reverse order
const std::string& bigint::get_value() const{
    return value;
}

//================================
// Helpers+
//================================

void bigint::remove_leading_zero() {
    while (value.length() > 1 && value.back() == '0'){
        value.pop_back();
    }
}

//================================
// Output Stream Operator
//================================

/* final output format in correct order */
std::ostream& operator<<(std::ostream& os, const bigint& bi){
    // print in reverse order
    const std::string& value = bi.get_value();
    for (int i = value.size() - 1; i >= 0; i--){
        os << value[i];
    }
    return os;

    // // print in internal order
    // os << bi.get_value();
    // return os;
}