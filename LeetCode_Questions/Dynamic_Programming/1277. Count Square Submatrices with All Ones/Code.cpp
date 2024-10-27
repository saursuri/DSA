/*
Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27
Time Complexity: O(M∗N)
Space Complexity: O(M∗N)
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int row=0; row<m; row++) dp[row][0] = matrix[row][0];
        for(int col=0; col<n; col++) dp[0][col] = matrix[0][col];

        for(int row=1; row<m; row++)
        {
            for(int col=1; col<n; col++)
            {
                if (matrix[row][col]==1)
                    // Count the cell as 1 + min of up, left, up-left
                    dp[row][col] = 1 + min(dp[row-1][col],min(dp[row][col-1],dp[row-1][col-1]));
            }
        }

        int count = 0;

        for(auto i: dp)
        {
            for(auto j:i)
            {
                count+=j;
            }
        } 

        return count;
    }
};
