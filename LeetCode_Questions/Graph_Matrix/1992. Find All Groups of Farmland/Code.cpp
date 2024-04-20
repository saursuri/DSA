/*
Problem Link: https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20
Time Complexity: O(m*n)
Space Complexity: O(m*n + k) --> k represents no of groups of farmland
*/
class Solution {
private:
    vector<int> findCoordUsingBFS(int row, int col,
                                  vector<vector<int>>& visited,
                                  vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        // Mark as visited
        visited[row][col] = 1;

        // Pairs to store start and end coordinates
        pair<int, int> start = {row, col};
        pair<int, int> end = {row, col};

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push(start);

        // To move in all 4 directions
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        // Perform BFS
        while (!q.empty()) {
            auto coor = q.front();
            q.pop();
            int cRow = coor.first;
            int cCol = coor.second;

            // Update the end coordinate
            end = coor;

            // Visit neighbors
            for (int i = 0; i < 4; i++) {
                int uRow = cRow + dr[i];
                int uCol = cCol + dc[i];

                // Boundary Checks
                // If not visited
                // If land
                if (0 <= uRow && uRow < m && 0 <= uCol && uCol < n &&
                    !visited[uRow][uCol] && land[uRow][uCol] == 1) {
                    visited[uRow][uCol] = 1;
                    q.push({uRow, uCol});
                }
            }
        }

        return {start.first, start.second, end.first, end.second};
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        // Visited array
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // To store ans
        vector<vector<int>> ans;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col] && land[row][col]) {
                    vector<int> group =
                        findCoordUsingBFS(row, col, visited, land);
                    ans.push_back(group);
                }
            }
        }

        return ans;
    }
};
