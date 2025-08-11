/*
------------------------------------------------------------
Program: Detect Endianness of the Machine
Author: Saurav Suri
Purpose:
    This program detects whether the system is Little Endian
    or Big Endian based on how multi-byte data is stored
    in memory.

Logic:
    1. Store a known 4-byte value (0x12345678) in an unsigned int.
    2. Access the first byte of that value by casting its address
       to a `char*` (since char is 1 byte).
    3. Check the first byte in memory:
       - If it is 0x78 (least significant byte), the system is 
         Little Endian.
       - If it is 0x12 (most significant byte), the system is 
         Big Endian.

Example:
    Memory representation for 0x12345678:
    Little Endian:  78 56 34 12   (LSB stored first)
    Big Endian:     12 34 56 78   (MSB stored first)

Time Complexity : O(1)  
Space Complexity: O(1)

Interview Tip:
    - Endianness is about byte ordering in memory.
    - Most modern x86/x86_64 CPUs are Little Endian.
    - Big Endian is common in some network protocols (network byte order).

Equivalent C Code:
------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>

bool is_little_endian()
{
    unsigned int var = 0x12345678;
    char* ptr = (char*)(&var);

    if (*ptr == 0x78)
        return true;

    return false;
}

int main()
{
    if (is_little_endian() == true)
        printf("Little Endian Machine\n");
    else
        printf("Big Endian Machine\n");

    return 0;
}
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

bool is_little_endian()
{
    unsigned int var = 0x12345678;

    char* ptr = (char *)(&var);

    if (*ptr == 0x78)
        return true;

    return false;
}

int main(){
    if (is_little_endian() == true)
        cout << "Little Endian Machine" << endl;
    else
        cout << "Big Endian Machine" << endl;

    return 0;
}
