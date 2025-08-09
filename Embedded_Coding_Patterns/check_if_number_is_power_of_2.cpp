/*
Checks if a given integer `n` is a power of two (works for both positive and negative numbers).

Two's complement representation:
- Positive numbers: normal binary (e.g.,  5  -> 0000...0101)
- Negative numbers: invert all bits of the absolute value, then add 1
  Example: -4
    4  -> 0000...0100
    ~4 -> 1111...1011
    +1 -> 1111...1100
- In two's complement, only one negative number is a power of two: INT_MIN (e.g., 1000...0000 for 32-bit int).
  This is -2^(31) in 32-bit signed integers.

Algorithm:
1. Zero check:
   - If n == 0 → not a power of two.
2. Bit property check:
   - A power of two has exactly one bit set in binary form.
   - For such numbers, `n & (n - 1)` == 0 (after casting to unsigned to avoid overflow).
3. Works for:
   - Positive powers of two: 1, 2, 4, 8, ...
   - Negative power of two (INT_MIN in 32-bit), if you want to count it.

Time Complexity: O(1)
Space Complexity: O(1)
*/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==0 || n == INT_MIN) return false;
        return (n & (n-1)) == 0;
    }
};
