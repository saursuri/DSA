/*
Problem Link: https://leetcode.com/problems/subsets/description/?envType=daily-question&envId=2024-05-21
Time Complexity: O(2^n)
Space Complexity: O(n)
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSubset;
        vector<vector<int>> subsets;
        findSubsets(0, nums, currSubset, subsets);
        return subsets;
    }
};
