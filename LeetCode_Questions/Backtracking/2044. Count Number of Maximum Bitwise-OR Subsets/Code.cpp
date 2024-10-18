/*
Problem Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
Time Complexity: O(2^n)
Space Complexity: O(1)
*/

class Solution {
    int countSubsets(int indx, int currOR, vector<int> &nums, int maxOR)
    {
        int n = nums.size();
        if (indx == n)
        {
            if (currOR == maxOR) return 1;
            else return 0;
        }

        int take = countSubsets(indx+1, currOR|nums[indx], nums, maxOR);
        int notTake = countSubsets(indx+1, currOR, nums, maxOR);

        return take+notTake;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxOR = 0;
        for (auto &it: nums) maxOR |= it;

        int count;
        return countSubsets(0, 0, nums, maxOR);
    }
};
