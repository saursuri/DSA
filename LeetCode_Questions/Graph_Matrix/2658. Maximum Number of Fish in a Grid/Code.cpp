/*
Problem Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

class cell{
    public:
        int row;
        int col;
};
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        int visited[10][10] = {0};
        function<int(int,int)> bfs = [&](int row, int col)
        {
            queue<cell> q;
            q.push({row, col});
            visited[row][col] = 1;

            int fishes = 0;
            while(!q.empty())
            {
                cell currCell = q.front();
                q.pop();

                fishes += grid[currCell.row][currCell.col];

                for (int i=0; i<4; i++)
                {
                    int newRow = currCell.row + dr[i];
                    int newCol = currCell.col + dc[i];

                    if (0 <= newRow && newRow < m && 0 <= newCol && newCol < n &&
                    !visited[newRow][newCol] && grid[newRow][newCol] != 0)
                    {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }

            }

            return fishes;

        };
        
        int maxFishes = 0;
        for (int row = 0; row<m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (!visited[row][col] && grid[row][col] != 0)
                {
                    maxFishes = max(maxFishes, bfs(row,col));
                }
            }
        }

        return maxFishes;

    }
};
