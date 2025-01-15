/*
Problem Link: https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15
Time Complexity: O(32)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimizeXor(int n, int k) {
        int setBits = __builtin_popcount(k); // Count set bits in k
        int result = 0;

        // Turn on bits of n starting from the most significant bit
        for (int i = 31; i >= 0 && setBits > 0; --i) {
            if ((n & (1 << i)) != 0) { // If bit i of n is set
                result |= (1 << i); // Set bit i in result
                --setBits;          // Decrease the count of needed set bits
            }
        }

        // If there are still set bits left, turn on the lowest available bits
        for (int i = 0; i < 32 && setBits > 0; ++i) {
            if ((result & (1 << i)) == 0) { // If bit i of result is not set
                result |= (1 << i); // Set bit i in result
                --setBits;          // Decrease the count of needed set bits
            }
        }

        return result;
    }
};
