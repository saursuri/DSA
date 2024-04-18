/*
Question Link: https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/
class Solution {
private:
    int calUsingBFS(int row, int col, vector<vector<int>>& grid,
                    vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        // Queue for BFS
        queue<pair<int, int>> q;

        // Push the start row col to the Queue
        q.push({row, col});

        // Mark it as visited
        visited[row][col] = 1;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        int count = 0;
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();

            int cRow = cell.first;
            int cCol = cell.second;

            // Visit neighbors
            for (int index = 0; index < 4; index++) {
                int uRow = cRow + dr[index];
                int uCol = cCol + dc[index];

                // If in bounds
                if (0 <= uRow && uRow < m && 0 <= uCol && uCol < n) {
                    // If a water cell that means a edge is there,
                    // Increase count
                    if (grid[uRow][uCol] == 0) {
                        count++;
                    }

                    // If a land cell and not visited, just visit the cell
                    if (grid[uRow][uCol] == 1 && !visited[uRow][uCol]) {
                        visited[uRow][uCol] = 1;
                        q.push({uRow, uCol});
                    }
                }

                // Else if out of bounds
                else
                    count++;
            }
        }
        return count;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    // Only one Island exist, so one BFS will suffice 
                    return calUsingBFS(row, col, grid, visited);
            }
        }

        return -1;
    }
};
