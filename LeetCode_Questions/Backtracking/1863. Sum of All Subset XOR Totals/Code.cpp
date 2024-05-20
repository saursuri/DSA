/*
Problem Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20
Time Complexity: O(2^n*n) --> Extra n to interate over subsets
Space Complexity: O(2^n*n)
*/
class Solution {
    void findSubsets(int index, vector<int>& nums, vector<int> &currSubset, vector<vector<int>> &subsets){
        int n = nums.size();
        if (index==n)
        {
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[index]);
        findSubsets(index+1, nums, currSubset, subsets);
        currSubset.pop_back();
        findSubsets(index+1, nums, currSubset, subsets);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        
        vector<int> currSubset;
        vector<vector<int>> subsets;
        findSubsets(0, nums, currSubset, subsets);

        int sum=0;
        for(auto subs: subsets)
        {
            int val = 0;
            for(auto num: subs)
            {
                val ^= num;
            }
            sum+=val;
        }

        return sum;
    }
};
