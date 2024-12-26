/*
Problem Link: https://leetcode.com/problems/target-sum/?envType=daily-question&envId=2024-12-26
Time Complexity: O(n*target)
Space Complexity: O(n*target)
*/

class Solution {
    int dp[21][3000];
    int solve(int target, int indx, vector<int>& nums) {
        int n = nums.size();
        if (n == indx) {
            if (target == 0) {
                return 1;
            } else
                return 0;
        }
        if (dp[indx][target + 1000] != -1)
            return dp[indx][target + 1000];

        return dp[indx][target+1000] = solve(target + nums[indx], indx + 1, nums) +
                                         solve(target - nums[indx], indx + 1, nums);

    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(target, 0, nums);
    }
};
