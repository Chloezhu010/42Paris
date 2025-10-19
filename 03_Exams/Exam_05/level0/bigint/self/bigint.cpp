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