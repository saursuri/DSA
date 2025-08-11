/*
------------------------------------------------------------
Program: Detect Stack Growth Direction
Author: Saurav Suri
Purpose:
    This program determines whether the stack grows upward 
    (towards higher memory addresses) or downward 
    (towards lower memory addresses) in the current system.

Logic:
    1. Declare two local variables sequentially in the function.
    2. Compare their memory addresses:
       - If the address of the first variable (var_a) is 
         LESS than the address of the second variable (var_b),
         then stack grows UPWARD.
       - Otherwise, stack grows DOWNWARD.
    3. The address ordering depends on how the system pushes 
       new local variables on the stack.
    
    Note:
    - On most modern systems, stack grows downward 
      (towards lower addresses).
    - However, some architectures or environments may have 
      upward-growing stacks.

Interview Tip:
    - Stack growth direction is architecture and ABI dependent.
    - This question often checks understanding of memory layout
      and stack frame allocation in function calls.

Equivalent C Code:
------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>

bool is_stack_upward_growing()
{
    unsigned int var_a = 0xAA;
    unsigned int var_b = 0xBB;
    
    if (&var_a < &var_b)
        return true;
    
    return false;
}

int main()
{
    if (is_stack_upward_growing() == true)
        printf("Stack is Upward Growing!\n");
    else
        printf("Stack is Downward Growing!\n");
    return 0;
}
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

bool is_stack_upward_growing()
{
    unsigned int var_a = 0xAA;
    unsigned int var_b = 0xBB;
  
    if (&var_a < &var_b)
        return true;
  
    return false;
}

int main()
{
    if (is_stack_upward_growing() == true)
        cout << "Stack is Upward Growing!" << endl;
    else
        cout << "Stack is Downward Growing!" << endl;

    return 0;
}
