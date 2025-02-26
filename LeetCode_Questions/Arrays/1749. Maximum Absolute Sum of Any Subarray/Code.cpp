/*
Kadane's Algorithm
Problem Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/?envType=daily-question&envId=2025-02-26
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        
        int localSumMin = 0;
        int localSumMax = 0;
        for (auto &it: nums)
        {
            localSumMax += it;
            localSumMin += it;

            if (localSumMax < 0) localSumMax = 0;
            if (localSumMin > 0) localSumMin = 0;
            maxSum = max(maxSum, localSumMax);
            minSum = min(minSum, localSumMin);
        }    

        return max(maxSum, abs(minSum));
    }
};
