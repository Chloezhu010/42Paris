Concepts:

  - Bag: A collection that allows duplicates (like a multiset)
  - Set: A collection that does NOT allow duplicates (unique values only)

Given Classes (Already Provided):

  1. bag (abstract) - Base interface with:
    - insert(int) - insert single value
    - insert(int*, int) - insert array of values
    - print() - display contents
    - clear() - remove all elements
  2. searchable_bag (abstract) - Extends bag with:
    - has(int) - check if value exists
  3. array_bag - Concrete implementation using dynamic array
  4. tree_bag - Concrete implementation using binary search tree

  ---
  Part 1: Implement searchable versions

  1. searchable_array_bag

  - Inherit from: array_bag AND searchable_bag
  - Implement: bool has(int) method
  - Logic: Search through the array to see if value exists
  - Must be: Orthodox canonical form (default constructor, copy constructor, assignment operator, destructor)

  2. searchable_tree_bag

  - Inherit from: tree_bag AND searchable_bag
  - Implement: bool has(int) method
  - Logic: Search the BST to see if value exists
  - Must be: Orthodox canonical form

  ---
  Part 2: Implement set class

  set

  - Wraps: A searchable_bag pointer
  - Purpose: A set wraps a searchable_bag and enforces the set property: no duplicates. The key difference from a bag is that
  when inserting, you must check if the element already exists before adding it.
  - Must implement:
    - Constructor taking a searchable_bag&
    - insert(int) - only insert if not already present
    - insert(int*, int) - insert array, skipping duplicates
    - has(int) - check if value exists
    - print() - display contents
    - clear() - remove all
    - get_bag() - return reference to underlying bag
  - Must be: Orthodox canonical form

## Implementation of set class
  1. The hierarchy is:
  bag (abstract - defines insert, print, clear)
    ↓
  searchable_bag (abstract - adds has method)
    ↓
  set (concrete - implements both bag and searchable_bag methods)