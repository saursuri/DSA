/*
Problem Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

struct ds{
    int cost;
    int row;
    int col;
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto func = [](ds &d1, ds &d2)
        {
            return d1.cost > d2.cost;
        };
        priority_queue<ds, vector<ds>, decltype(func)> pq(func);

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        vector<vector<int>> visited(m, vector<int>(n, 0));
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto pqTop = pq.top();
            pq.pop();
            int cost = pqTop.cost;
            int row = pqTop.row;
            int col = pqTop.col;

            if (visited[row][col]) continue;  // Skip already processed cells
            visited[row][col] = 1;           // Mark cell as visited

            if (row == m - 1 && col == n - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int cR = row + dr[i];
                int cC = col + dc[i];

                if (0 <= cR && cR < m && 0 <= cC && cC < n && !visited[cR][cC]) {
                    if (grid[row][col] == i + 1) {
                        pq.push({cost, cR, cC}); // No cost for the correct direction
                    } else {
                        pq.push({cost + 1, cR, cC}); // Add cost for changing direction
                    }
                }
            }
        }

        return -1; // If the destination is unreachable
    }
};
