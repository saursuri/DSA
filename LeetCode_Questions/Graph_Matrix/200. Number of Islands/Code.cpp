/*
Problem Link: https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

class Solution {
private:
    void traverseUsingDFS(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &visited)
    {   
        int m = grid.size();
        int n = grid[0].size();

        // Mark the cell as visited
        visited[row][col] = 1;

        // To Traverse in all 4 directions
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        // Visit neighbors
        for(int index=0; index<4; index++)
        {
            int uRow = row + dr[index];
            int uCol = col + dc[index];

            // If in boundary, not visited and a land cell
            if ( 0<=uRow && uRow<m && 0<=uCol && uCol<n
                && !visited[uRow][uCol] && grid[uRow][uCol]=='1')
            {
                traverseUsingDFS(uRow, uCol, grid, visited);
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Create visited array
        vector<vector<int>> visited(m,vector<int>(n,0));

        // Count to store the number of islands
        int count=0;
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                // Visit only if not visited and a land cell
                if (!visited[row][col] && grid[row][col]=='1')
                {   
                    count++;
                    traverseUsingDFS(row,col,grid,visited);
                }
            }
        }

        return count;
    }
};
