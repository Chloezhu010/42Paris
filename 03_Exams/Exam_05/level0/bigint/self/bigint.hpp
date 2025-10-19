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

        // addition operator
        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        
        // helpers
        void remove_leading_zero();

        // getters
        const std::string& get_value() const;

};

// output stream operator
std::ostream& operator<<(std::ostream& os, const bigint& bi);

#endif