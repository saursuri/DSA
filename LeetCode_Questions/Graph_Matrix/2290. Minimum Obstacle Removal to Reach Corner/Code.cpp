/*
Problem Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/?envType=daily-question&envId=2024-11-28
Time Complexity: O(M*N*Log(M*N))
Space Complexity: O(M*N)
*/

class elems {
public:
    int obstacle;
    int row;
    int col;
};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto compare = [](const elems& e1, const elems& e2) {
            return e1.obstacle > e2.obstacle; // Min-heap based on obstacles
        };

        priority_queue<elems, vector<elems>, decltype(compare)> q(compare);
        q.push({0, 0, 0}); // Start with 0 obstacles at (0, 0)

        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Visited grid
        visited[0][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int r = q.top().row;
            int c = q.top().col;
            int o = q.top().obstacle;
            q.pop();

            // If we've reached the bottom-right corner, return the result
            if (r == m - 1 && c == n - 1) {
                return o;
            }

            // Visit neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    if (grid[nr][nc] == 1) {
                        q.push({o + 1, nr, nc});
                    } else {
                        q.push({o, nr, nc});
                    }
                }
            }
        }

        return -1; // Shouldn't reach here if there's a valid path
    }
};
