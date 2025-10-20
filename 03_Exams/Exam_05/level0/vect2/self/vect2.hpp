#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
    private:
        int x;
        int y;

    public:
        // constructors
        vect2();
        vect2(int x, int y);
        vect2(const vect2& other);
        // destructor
        ~vect2();
        // asssignment operator
        vect2& operator=(const vect2& other);
        // [] operator overloads
        const int& operator[](size_t index) const;
        int& operator[](size_t index);
        // increment operators
        vect2& operator++(); // prefix
        vect2 operator++(int); // posfix
        // decrement operators
        vect2& operator--(); // prefix
        vect2 operator--(int); // postfix
        // compound operators
        vect2& operator+=(const vect2& other);
        vect2& operator-=(const vect2& other);
        vect2& operator*=(int n);
        // binary operators
        vect2 operator+(const vect2& other) const;
        vect2 operator-(const vect2& other) const;
        // unary minus operator
        vect2 operator-() const;
        // comparison operators
        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;


        // getters
        int getX() const;
        int getY() const;

};

// binary operators
vect2 operator*(const vect2& v, int n);
vect2 operator*(int n, const vect2& v);

// stream output operator
std::ostream& operator<<(std::ostream& os, const vect2& v);


#endif