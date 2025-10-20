#include "vect2.hpp"

//================================
// Constructors
//================================

vect2::vect2(): x(0), y(0) {}

vect2::vect2(int x, int y): x(x), y(y) {}

vect2::vect2(const vect2& other): x(other.x), y(other.y) {}

//================================
// Destructor
//================================ 

vect2::~vect2(){}

//================================
// Assignment Operator
//================================

vect2& vect2::operator=(const vect2& other){
    if (this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}

//================================
// [] Operator Overloads
//================================

const int& vect2::operator[](size_t index) const {
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        return x; // undefined behavior, default to x
}

int& vect2::operator[](size_t index) {
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        return x; // undefined behavior, default to x
}

//================================
// Increment/ Decrement Operators
//================================

// prefix increment
vect2& vect2::operator++(){
    ++x;
    ++y;
    return *this;
}

// postfix increment
vect2 vect2::operator++(int){
    vect2 original(*this);
    ++x;
    ++y;
    return original;
}

// prefix decrement
vect2& vect2::operator--(){
    --x;
    --y;
    return *this;
}

// postfix decrement
vect2 vect2::operator--(int){
    vect2 original(*this);
    --x;
    --y;
    return original;
}

//================================
// Compound Operators
//================================

vect2& vect2::operator+=(const vect2& other){
    x += other.x;
    y += other.y;
    return *this;
}

vect2& vect2::operator-=(const vect2& other){
    x -= other.x;
    y -= other.y;
    return *this;
}

vect2& vect2::operator*=(int n){
    x *= n;
    y *= n;
    return *this;
}

//================================
// Binary Operators
//================================

vect2 vect2::operator+(const vect2& other) const{
    vect2 result(*this);
    result += other;
    return result;
}

vect2 vect2::operator-(const vect2& other) const{
    vect2 result(*this);
    result -= other;
    return result;
}

vect2 operator*(const vect2& v, int n){
    vect2 result(v);
    result *= n;
    return result;
}

vect2 operator*(int n, const vect2& v){
    return v * n;
}

//================================
// Unary Minus Operator
//================================

vect2 vect2::operator-() const{
    return vect2(-x, -y);
}

//================================
// Comparison Operators
//================================

bool vect2::operator==(const vect2& other) const{
    return (x == other.x && y == other.y);
}

bool vect2::operator!=(const vect2& other) const {
    return !(*this == other);
}

//================================
// Getters
//================================

int vect2::getX() const {
    return x;
}

int vect2::getY() const {
    return y;
}

//================================
// Stream Output Operator
//================================

std::ostream& operator<<(std::ostream& os, const vect2& v){
    os << "{" << v.getX() << ", " << v.getY() << "}";
    return os;
}