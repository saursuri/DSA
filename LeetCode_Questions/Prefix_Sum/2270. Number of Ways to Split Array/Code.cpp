/*
Problem Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long prefixSum = 0;
        int count = 0;
        for (int i = 0; i < n - 1; i++) { // Split must leave at least one element on the right
            prefixSum += nums[i];
            long long suffixSum = totalSum - prefixSum;
            if (prefixSum >= suffixSum) {
                count++;
            }
        }
        
        return count;
    }
};
