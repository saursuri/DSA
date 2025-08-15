/*
Problem Link: https://leetcode.com/problems/power-of-four/description/?envType=daily-question&envId=2025-08-15
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        while (n % 4 == 0)
        {
            n = n / 4;
        }
        
        return (n == 1) ? true : false;
    }
};
