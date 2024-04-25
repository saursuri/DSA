/*
Problem Link: https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25
Time Complexity: O(n*26)
Space Complexity: O(n*27)
*/
class Solution {
private:
    int lisUtil(int index, char last, string &s, int k, vector<vector<int>> &dp)
    {   
        int n = s.length();

        // When index reaches end that means empty string
        // LIS of empty string is 0
        if(index==n) return 0;

        if(dp[index][last-'`']!=-1) return dp[index][last-'`'];

        int take = 0;
        if (last=='`' || abs(s[index]-last)<=k)
            take = 1 + lisUtil(index+1, s[index], s, k, dp);

        int notTake = lisUtil(index+1, last, s, k, dp);

        return dp[index][last-'`'] = max(take, notTake);
    }

public:
    int longestIdealString(string s, int k) {
        
        int  n = s.length();
        vector<vector<int>> dp(n,vector<int>(27,-1));
        return lisUtil(0,'`',s,k,dp);
    }
};
