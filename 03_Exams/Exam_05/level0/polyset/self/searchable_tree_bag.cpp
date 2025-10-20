#include "searchable_tree_bag.hpp"

//================== Constructor / Destructor =================//

searchable_tree_bag::searchable_tree_bag(): tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other): tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other){
    if (this != &other){
        tree_bag::operator=(other);
    }
    return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::has(int value) const {
    tree_bag::node *current = this->tree;
    while (current != nullptr) {
        if (value == current->value)
            return true;
        else if (value < current->value)
            current = current->l;
        else
            current = current->r;
    }
    return false;
}