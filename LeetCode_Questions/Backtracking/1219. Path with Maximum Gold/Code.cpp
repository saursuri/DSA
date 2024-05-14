/*
Problem Link: https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14
Time Complexity: O(m*n*4^(cells having Gold))
Space Complexity: O(4^(cells having Gold))
*/

class Solution {
    int getMaximumGoldUtil(int row, int col, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};


        int goldCollected = grid[row][col];
        grid[row][col]=0;
        int maxGold = 0;
        for(int index=0; index<4; index++)
        {
            int uRow = row + dr[index];
            int uCol = col + dc[index];

            if (0<=uRow && uRow<m && 0<=uCol && uCol<n && grid[uRow][uCol]!=0)
            {
                maxGold = max(maxGold, getMaximumGoldUtil(uRow,uCol,grid));
            }
        }

        grid[row][col]=goldCollected;

        return goldCollected + maxGold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxGold = 0;
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if (grid[row][col]!=0)
                {   
                    maxGold = max(maxGold,getMaximumGoldUtil(row,col,grid));
                }
            }
        }

        return maxGold;
        
    }
};
