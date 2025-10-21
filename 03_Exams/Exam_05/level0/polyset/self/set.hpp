#ifndef SET_HPP
#define SET_HPP

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set {
    private:
        searchable_bag& _bag; // underlying bag reference

    public:
        // construct
        set(searchable_bag &bag);
        set(const set &other);
        // assignment operator
        set& operator=(const set &other);
        // destruct
        ~set();

        // bag interface
        void insert(int value);
        void insert(int *array, int size);
        void print() const;
        void clear();
        // searchable_bag interface
        bool has(int value) const;
        // getter
        searchable_bag& get_bag();
        const searchable_bag& get_bag() const;
};


#endif