// FILE GIVEN DURING EXAM, DO NOT CHANGE!!!

#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include <cstdlib>
#include <iostream>
#include "set.hpp"

int main(int ac, char **av)
{
    if(ac == 1)
        return 1;
    // test searchable_tree_bag and searchable_array_bag
    searchable_bag *t = new searchable_tree_bag;
    searchable_bag *a = new searchable_array_bag;
    for (int i = 1; i < ac; i++)
    {
        t->insert(atoi(av[i]));
        a->insert(atoi(av[i]));
    }
    std::cout << "print results: " << std::endl;
    std::cout << "  tree results: ";
    t->print();
    std::cout << "  array results: ";
    a->print();
    for(int i = 1; i < ac; i++)
    {
        std::cout << t->has(atoi(av[i])) << std::endl;
        std::cout << t->has(atoi(av[i]) - 1) << std::endl;
        std::cout << a->has(atoi(av[i])) << std::endl;
        std::cout << a->has(atoi(av[i]) - 1) << std::endl;
    }
    t->clear();
    a->clear();

    // test set with searchable_tree_bag and searchable_array_bag
    const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
    std::cout << "print results: " << std::endl;
    tmp.print();
    tmp.has(1);
    set sa(*a);
    set st(*a);

    // loop through the input, convert them into int, then insert into the sets
    for(int i = 1; i < ac; i++)
    {
        st.insert(atoi(av[i]));
        sa.insert(atoi(av[i]));
    }
    // check if the 1st argument is in the array-based set
    sa.has(atoi(av[1]));
    // print the sets and their underlying bags
    sa.print();
    sa.get_bag().print();
    st.print();
    // clear the array-based set
    sa.clear();

    // insert a predefined array into the array-based set
    int arr[] = {1, 2, 3, 4,};
    sa.insert(arr, 4);
    sa.print();
}