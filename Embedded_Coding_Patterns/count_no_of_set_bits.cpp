/*
------------------------------------------------------------
Program: Count Number of Set Bits in an Integer
Author: Saurav Suri
Purpose:
    This program counts the number of set bits (1s) in the 
    binary representation of an unsigned integer using 
    Brian Kernighan’s algorithm.

Logic:
    1. Brian Kernighan’s Algorithm:
       - When you do `var & (var - 1)`, it clears the least 
         significant set bit of `var`.
       - Repeat this process and count how many times it runs 
         until `var` becomes zero.
    2. This is more efficient than checking each bit one by one.

Example:
    Input:  var = 0x0F (binary 0000 1111)
    Step 1: var = var & (var - 1) → clears one set bit
    Step 2: repeat until var = 0
    Count = 4 (since there were 4 set bits)

Time Complexity : O(k) where k = number of set bits  
Space Complexity: O(1)

Interview Tip:
    - This is faster than looping through all bits when the 
      number of set bits is small compared to total bits.
    - Related problems: Hamming distance, population count.

Equivalent C Code:
------------------------------------------------------------
#include <stdio.h>

unsigned int count_no_of_set_bits(unsigned int var)
{
    int count = 0;
    while (var)
    {
        var = var & (var - 1);
        count++;
    }
    return count;
}

int main()
{
    unsigned int var = 0xABCD1234;
    printf("No of Set Bits: %u\n", count_no_of_set_bits(var));
    return 0;
}
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Function to count number of set bits using Brian Kernighan's Algorithm
unsigned int count_no_of_set_bits(unsigned int var)
{
    int count = 0;

    while (var)
    {
        var = var & (var - 1); // Clear the least significant set bit
        count++;
    }

    return count;
}

int main()
{
    unsigned int var = 0xABCD1234;

    cout << "No of Set Bits: " << count_no_of_set_bits(var) << endl;

    return 0;
}
