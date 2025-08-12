/*
------------------------------------------------------------
Program: Align Address to 4-byte Boundary
Author: Saurav Suri
Purpose:
    This program aligns a given address to the nearest 4-byte 
    boundary in memory.  
    Alignment is important in embedded systems for:
      - Performance optimization
      - Avoiding unaligned memory access faults

Logic:
    1. Add 3 to the given address:
       - This ensures that even if the address is already aligned,
         it remains unchanged after masking.
       - If it is not aligned, adding 3 moves it up to the next
         multiple of 4.
    2. Apply bitmask (~0x3):
       - 0x3 in binary is `000...011`
       - ~0x3 in binary is `111...100`
       - ANDing with ~0x3 clears the last two bits, forcing alignment
         to a multiple of 4.

Example:
    Input Address: 0x4001 (binary ...0100 0000 0000 0001)
    Add 3        : 0x4004 (...0100 0000 0000 0100)
    Mask (~0x3)  : 0x4004 (...0100 0000 0000 0100) → aligned

Time Complexity : O(1)  
Space Complexity: O(1)

Interview Tip:
    - Commonly used for aligning buffer start addresses
      for DMA transfers, peripherals, or cache optimization.
    - General formula for aligning `x` to `n` bytes (n power of 2):
          aligned = (x + (n - 1)) & ~(n - 1)

Equivalent C Code:
------------------------------------------------------------
#include <stdio.h>

void align_4_bytes(unsigned int *addr)
{
    unsigned int temp_addr = *addr;
    *addr = (temp_addr + 3) & (~0x3);
}

int main()
{
    unsigned int address = 0x4001;
    align_4_bytes(&address);

    printf("0x%X\n", address);
    return 0;
}
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void align_4_bytes(unsigned int *addr)
{
    unsigned temp_addr = *addr;

    // Add 3 and mask lower 2 bits to align to 4-byte boundary
    *addr = (temp_addr + 3) & (~0x3); 
}

int main()
{
    unsigned int address = 0x4001;
    align_4_bytes(&address);

    cout << hex << "0x" << address << endl;
  
    return 0;
}
