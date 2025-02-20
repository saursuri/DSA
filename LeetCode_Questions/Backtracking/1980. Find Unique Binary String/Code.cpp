/*
Problem Link: https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

class Solution {
    int n;
    unordered_set<string> hash;
    bool solve(int i, string &temp, string &ans)
    {
        if (i == n)
        {
            if (hash.count(temp) == 0)
            {
                ans = temp;
                return true;
            }
            else return false;
        }

        for (const auto &option: {'0','1'})
        {   
            temp.push_back(option);
            if (solve(i+1, temp, ans) == true)
                return true;
            temp.pop_back();
        }

        return false;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        string temp;
        string ans;
        int n = nums.size();

        for (const auto &it: nums)
        {
            hash.insert(it);
        }

        this->n = n;
        solve (0,temp, ans);
        return ans;

    }
};
