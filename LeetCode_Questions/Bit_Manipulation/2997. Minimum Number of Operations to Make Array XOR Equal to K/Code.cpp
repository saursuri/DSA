/*
Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        int total = nums[0];

        for(int i=1; i<n; i++)
        {
            total^=nums[i];
        }

        // Find the difference of bits to be changed
        total^=k;

        // Count total no of set bits in total
        return __builtin_popcount(total);

    }
};
