/*
NVIDIA Interview Question
------------------------------------------------------------
Program: Count Differing Bits Between Two Integers
Author: Saurav Suri
Purpose:
    This program counts how many bit positions differ between 
    two unsigned integers `a` and `b`. This tells us how many 
    bit flips would be required to convert one into the other.

Logic:
    1. Perform XOR (`a ^ b`):
       - Same bits → 0
       - Different bits → 1
       - Result: Binary number with 1s at differing positions.
    2. Count set bits in the XOR result:
       - Use Brian Kernighan’s algorithm:
         - `x & (x - 1)` clears the least significant set bit.
         - Increment counter until `x` becomes 0.

Example:
    a    = 1010
    b    = 0011
    a^b  = 1001 → two differing bits → output = 2

Time Complexity : O(k), where k = number of differing bits  
Space Complexity: O(1)

Interview Tip:
    - This is a common bit-manipulation problem.
    - Brian Kernighan’s algorithm is more efficient than 
      checking each bit individually.
    - Similar logic is used in problems like Hamming distance.

Equivalent C Code:
------------------------------------------------------------
#include <stdio.h>

int count_bits_to_flip(unsigned int a, unsigned int b) {
    unsigned int x = a ^ b;
    int count = 0;
    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}

int main() {
    unsigned int num1 = 0xA0A0A0A0;
    unsigned int num2 = 0x60606060;
    printf("%d\n", count_bits_to_flip(num1, num2));
    return 0;
}
------------------------------------------------------------
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
