Problem Overview

  You need to create a class that stores arbitrarily large unsigned integers (bigger than what standard types can
  hold) by storing digits internally.

  Core Logic & Approach

  1. Internal Storage

  - Store the number as a container of digits (typically std::vector<int> or std::string)
  - Key decision: Store digits in reverse order (least significant digit first)
    - Example: 1337 stored as [7, 3, 3, 1]
    - Makes addition and shifting operations much easier

  2. Constructors Needed

  From the main, you need:
  - Default constructor: Initialize to 0
  - Integer constructor: bigint(42) - convert int to bigint
  - String constructor: bigint("42") - parse string to bigint
  - Copy constructor: bigint e(d) - copy another bigint

  3. Addition Logic (+ and +=)

  - Add digit by digit from least significant
  - Keep track of carry (when sum >= 10)
  - Propagate carry to next position
  - Continue until all digits processed and no carry remains

  4. Subtraction Logic (-)

  - You see c - a in the main
  - Since it's unsigned, you don't need to handle negative results
  - Subtract digit by digit with borrowing
  - Similar to elementary school subtraction

  5. Increment Operators (++)

  - Pre-increment (++b): increment then return
  - Post-increment (b++): return old value then increment
  - Just add 1 to the bigint (reuse addition logic)

  6. Digit Shift Operators (<< and >>=)

  - Left shift (<<): Multiply by 10^n
    - 42 << 3 = 42000 (append 3 zeros)
    - Just add n zeros to the end (or beginning if reversed storage)
  - Right shift (>>): Divide by 10^n
    - 1337 >> 2 = 13 (remove 2 digits from right)
    - Remove n digits from the end

  7. Comparison Operators

  Needed: ==, !=, <, >, <=, >=

  Logic:
  - First compare lengths (more digits = bigger number, assuming no leading zeros)
  - If same length, compare digit by digit from most significant down
  - Implement == and <, derive others from these

  8. Output Operator (<<)

  - Print the number in base 10
  - Critical: No leading zeros (except for the number 0 itself)
  - If storing in reverse, print in reverse order

  Corner Cases to Consider

  1. Zero Handling

  - Default constructor should create 0
  - Zero should be represented consistently (single digit 0, not empty)
  - 0 << 5 should still be 0, not "00000"

  2. Leading Zeros

  - After operations, remove leading zeros
  - Example: 1000 - 999 = 1 (not 0001)
  - Keep at least one digit (the number 0)

  3. Right Shift Beyond Length

  - 42 >> 5 should give 0 (shifting away all digits)
  - Don't access invalid indices

  4. String Constructor Edge Cases

  - Empty string
  - String with leading zeros: "00042" should become 42
  - String "0" should work correctly

  5. Self-Assignment

  - a += a should work correctly
  - Copy data before modifying if needed

  6. Carry Propagation

  - In addition, carry might extend beyond both operands
  - Example: 999 + 1 = 1000 (new digit added)

  7. Different Lengths in Operations

  - Adding/comparing numbers of different lengths
  - Don't assume operands have same size

  8. Subtraction Edge Cases

  - Since unsigned, what if result would be negative?
  - The exam probably won't test this based on the main
  - But consider: should result be 0? Or undefined behavior?

  Recommended Implementation Order

  1. Start with storage (vector/string of digits)
  2. Integer constructor first (easier than string)
  3. Output operator (for debugging)
  4. Addition (needed for increment)
  5. Increment operators
  6. String constructor
  7. Comparison operators
  8. Shift operators
  9. Subtraction (if needed)
  10. Test thoroughly with the provided main

  Tips

  - Create helper function to remove leading zeros
  - Reuse operators (implement +=, then + uses +=)
  - For comparisons, implement < and ==, derive the rest

  Notes
  - Diff between += and +
    - Code behavior
        ```cpp
        bigint a(10);
        bigint b(5);

        // Using +=
        a += b;  // a is now 15, b is still 5
                // a was MODIFIED

        // Using +
        bigint c = a + b;  // a is still 15, b is still 5, c is 20
                            // a and b were NOT modified, NEW object created
        ```
    - Return type
        ```cpp
        bigint& operator+=(const bigint& other);  // Returns reference (&)
                                                    // Returns *this (the modified object)

        bigint operator+(const bigint& other) const;  // Returns new object (no &)
                                                        // Returns a copy
                                                        // const function (doesn't modify)
        ```
- Diff between ++b and b++
    - Code behavior
        ```cpp
        int b = 5;

        int x = ++b;  // Pre: b becomes 6, then x = 6
                        // Result: b = 6, x = 6

        int b = 5;
        int y = b++;  // Post: y = 5 (old value), then b becomes 6
                        // Result: b = 6, y = 5
        ```
