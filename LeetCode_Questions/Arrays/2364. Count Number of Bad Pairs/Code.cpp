/*
Problem Link: https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> diffMap;
        long long allPairs = ((long long)n * (long long)(n-1))/2;

        for (int i=0; i<n; i++)
        {
            diffMap[nums[i] - i] ++;
        }

        long long validPairs = 0;
        for (auto &it: diffMap)
        {
            validPairs += ((long long)it.second*(long long)(it.second-1))/2;
        }

        return allPairs - validPairs;

    }
};
