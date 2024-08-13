/*
Problem Link: https://leetcode.com/problems/combination-sum-ii/?envType=daily-question&envId=2024-08-13
Time Complexity: O(2^n)
Space Complexity: O(n) --> temp vector and recursion stack
*/
class Solution {
private:
    void solve(vector<vector<int>> &ans, int target, vector<int> &temp, vector<int> &candidates, int i)
    {
        if (target < 0) return;
        
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (target < 0) return;

        for(int j=i; j<candidates.size(); j++)
        {
            // Not take the element if element is same
            if (j>i && candidates[j] == candidates[j-1]) continue;

            temp.push_back(candidates[j]);
            solve(ans, target - candidates[j], temp, candidates, j+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, target, temp, candidates, 0);

        return ans;
    }
};
