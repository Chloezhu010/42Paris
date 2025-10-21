#include "set.hpp"

// construct
set::set(searchable_bag& bag): _bag(bag) {}

set::set(const set& other): _bag(other._bag) {}

// assignment operator
set& set::operator=(const set& other){
    (void)other; // since _bag is a reference, no need to reassign it
    return *this;
}

// destruct
set::~set() {}

// searchable_bag interface
bool set::has(int value) const {
    return _bag.has(value);
}

// bag interface
void set::insert(int value){
    if (!has(value))
        _bag.insert(value);
}

void set::insert(int* array, int size){
    for (int i = 0; i < size; i++) {
        insert(array[i]);
    }
}

void set::print() const {
    _bag.print();
}

void set::clear() {
    _bag.clear();
}

// getter
searchable_bag& set::get_bag() {
    return _bag;
}

const searchable_bag& set::get_bag() const {
    return _bag;
}

