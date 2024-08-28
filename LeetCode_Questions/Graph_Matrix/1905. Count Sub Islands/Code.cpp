/*
Problem Link: https://leetcode.com/problems/count-sub-islands/?envType=daily-question&envId=2024-08-28
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/


class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, bool &flag)
    {
        if (grid[r][c] == 2) flag = false;

        int m = grid.size();
        int n = grid[0].size();

        // Mark as visited
        grid[r][c] = -1;

        // Visit the neighbors
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int i=0; i<4; i++)
        {
            int aR = r + dr[i];
            int aC = c + dc[i];

            if (0 <= aR && aR < m && 0 <= aC && aC < n && (grid[aR][aC] == 1 || grid[aR][aC] == 2))
            {
                dfs(grid, aR, aC, flag);
            }
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) 
                    grid2[i][j] = 2;
                
            }
        }

        int island_count = 0;

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid2[i][j] == 1 || grid2[i][j] == 2)
                {   
                    bool flag = true;
                    dfs(grid2, i, j, flag);
                    
                    if (flag) island_count++;
                }
            }
        }

        return island_count;
    }
};
