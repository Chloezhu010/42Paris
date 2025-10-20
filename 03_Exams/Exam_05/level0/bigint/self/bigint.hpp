#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

class bigint
{
    private:
        // internal representation of the bigint
        std::string value;
    public:
        // constructors
        bigint();
        bigint(unsigned int num);
        bigint(const std::string& str);
        bigint(const bigint& other);
        // assignment operator
        bigint& operator=(const bigint& other);
        // destructor
        ~bigint();

        // addition operators
        bigint& operator+=(const bigint& other);
        bigint operator+(const bigint& other) const;
        // increment operators
        bigint& operator++(); // prefix
        bigint operator++(int); // postfix
        // comparison operators
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        // shift operators
        bigint& operator<<=(unsigned int shift);
        bigint& operator>>=(unsigned int shift);
        bigint operator<<(unsigned int shift) const;
        bigint operator>>(unsigned int shift) const;

        // subtraction operators
        bigint& operator-=(const bigint& other);
        bigint operator-(const bigint& other) const;        
        
        // helpers
        void remove_leading_zero();

        // getters
        const std::string& get_value() const;

};

// output stream operator
std::ostream& operator<<(std::ostream& os, const bigint& bi);

#endif