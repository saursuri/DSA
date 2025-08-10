/*
NVIDIA Interview Question
============================ SUMMARY ============================
Purpose:
--------
This program swaps the odd and even bits of an unsigned integer.
- Bit positions are numbered from right to left (LSB is position 0).
- "Even" bits = positions 0, 2, 4, ...
- "Odd" bits  = positions 1, 3, 5, ...

How it works:
-------------
1. Use two bit masks:
   - odd_bit_mask  = 0x55555555 (binary: 010101...0101) selects bits at even positions.
   - even_bit_mask = 0xAAAAAAAA (binary: 101010...1010) selects bits at odd positions.

2. To swap:
   - Shift right by 1: moves even bits into odd positions.
     Apply odd_bit_mask to keep bits only in odd positions.
   - Shift left by 1: moves odd bits into even positions.
     Apply even_bit_mask to keep bits only in even positions.
   - Combine both results with bitwise OR.

Example:
--------
Input :  1010 (binary)  -> decimal 10
Output:  0101 (binary)  -> decimal 5
---------------------------------------------------------------
Time complexity : O(1) (bitwise operations on a fixed-size integer)
Space complexity: O(1)
================================================================
*/

#include <iostream>
#include <bitset>
using namespace std;

// Helper function to print binary representation of an unsigned int
void print_binary(unsigned int num) {
    // bitset<32> ensures 32-bit binary representation
    cout << bitset<32>(num);
}

// Function to swap odd and even bits of a given unsigned integer
void swap_odd_with_even_bits(unsigned int *num_ptr)
{
    unsigned int num_ptr_val = *num_ptr;

    // Mask for even-numbered bit positions (0, 2, 4, ...)
    unsigned int odd_bit_mask = 0x55555555;

    // Mask for odd-numbered bit positions (1, 3, 5, ...)
    unsigned int even_bit_mask = 0xAAAAAAAA;

    // Swap by shifting and masking, then combining
    *num_ptr = ((num_ptr_val >> 1) & odd_bit_mask) | ((num_ptr_val << 1) & even_bit_mask);
}

int main()
{
    unsigned int num1 = 0x9A9A9A9A;
    unsigned int num2 = 0x65656565;

    cout << "Before swap:\n";
    cout << "Number-1 Hex: 0x" << hex << num1 << "  Binary: ";
    print_binary(num1);
    cout << endl;

    cout << "Number-2 Hex: 0x" << hex << num2 << "  Binary: ";
    print_binary(num2);
    cout << endl;

    swap_odd_with_even_bits(&num1);
    swap_odd_with_even_bits(&num2);

    cout << "\nAfter swap:\n";
    cout << "Number-1 Hex: 0x" << hex << num1 << "  Binary: ";
    print_binary(num1);
    cout << endl;

    cout << "Number-2 Hex: 0x" << hex << num2 << "  Binary: ";
    print_binary(num2);
    cout << endl;

    return 0;
}
