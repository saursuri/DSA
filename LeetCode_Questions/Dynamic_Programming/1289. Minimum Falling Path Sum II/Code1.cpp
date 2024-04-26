/*
Problem Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/submissions/1242637923/?envType=daily-question&envId=2024-04-26
Time Complexity: O(n^3)
Space Complexity: O(n^2) + Recursion Stack
*/
class Solution {
private:
    int minFallingPathSumUtil(int index, int prevIndex, vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        int n = grid.size();
        // If index increases by last row
        // Path sum will be 0
        if(index==n) return 0;
        
        if (dp[index][prevIndex]!=-1) return dp[index][prevIndex];

        int minSum = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(i==prevIndex) continue;
            
            int localSum = grid[index][i] + minFallingPathSumUtil(index+1,i,grid,dp);
            minSum = min(minSum, localSum);
        }

        return dp[index][prevIndex] = minSum;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        int minSum = INT_MAX;
        for(int col=0; col<n; col++)
        {
            int localSum = grid[0][col] + minFallingPathSumUtil(1, col, grid, dp);
            cout << localSum << endl;
            minSum = min(minSum, localSum);
        }

        return minSum;
    }
};
