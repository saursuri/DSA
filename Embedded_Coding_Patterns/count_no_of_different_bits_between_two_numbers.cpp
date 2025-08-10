/*
NVIDIA Interview Questions
============================ SUMMARY ============================
Purpose:
--------
This program counts how many bits differ between two unsigned integers
`a` and `b`. This tells us how many bit positions would need to be flipped
to convert `a` into `b`.

How it works:
-------------
1. XOR (`a ^ b`):
   - Bits that are the same produce 0.
   - Bits that differ produce 1.
   - Result: A binary number where each 1 indicates a differing bit.

2. Count the number of set bits (1s) in the XOR result:
   - Uses Brian Kernighan’s algorithm:
     - `x & (x - 1)` clears the least significant set bit.
     - Increment count each time until x becomes 0.

Example:
--------
a    = 1010  
b    = 0011  
a^b  = 1001  → two bits differ → output = 2

---------------------------------------------------------------
Time complexity : O(k) where k = number of differing bits
Space complexity: O(1)
================================================================
*/

#include <iostream>
using namespace std;

// Function to count differing bits between a and b
int count_bits_to_flip(unsigned int a, unsigned int b) {
    // XOR will have 1s where a and b differ
    unsigned int x = a ^ b;

    int count = 0;

    // Brian Kernighan’s algorithm to count set bits
    while (x) {
        x = x & (x - 1); // clear the least significant set bit
        count++;
    }
    return count;
}

int main()
{
    unsigned int num1 = 0xA0A0A0A0; // First number
    unsigned int num2 = 0x60606060; // Second number

    cout << count_bits_to_flip(num1, num2) << endl; // Output: differing bit count
  
    return 0;
}
