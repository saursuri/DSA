/*
Problem Link: https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2025-01-23
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> Rows(grid.size());
        vector<int> Col(grid[0].size());
        
        // Calculate row and column sums
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                Rows[i] += grid[i][j];
                Col[j] += grid[i][j];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && (Rows[i] > 1 || Col[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
