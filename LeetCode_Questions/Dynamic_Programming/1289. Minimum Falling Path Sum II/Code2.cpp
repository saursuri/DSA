/*
Problem Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/?envType=daily-question&envId=2024-04-26
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class cell {
public:
    int index;
    int value;
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        cell firstMin = {-1, 0};
        cell secondMin = {-1, 0};

        // Move across last row of the grid
        for (int col = 0; col < n; col++) {
            // If minIndex is -1 or grid current cell is smaller
            // than minVal --> Update the val and Index
            if (firstMin.index == -1 || grid[n - 1][col] <= firstMin.value) {
                secondMin = firstMin;
                firstMin = {col, grid[n - 1][col]};
            } else if (secondMin.index == -1 ||
                       grid[n - 1][col] <= secondMin.value) {
                secondMin = {col, grid[n - 1][col]};
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            cell first = {-1, 0};
            cell second = {-1, 0};

            for (int col = 0; col < n; col++) {
                int ans = grid[row][col];

                // If current col is same as minColIndex1
                if (col == firstMin.index) {
                    ans += secondMin.value;
                } else {
                    ans += firstMin.value;
                }

                if (first.index == -1 || ans <= first.value) {
                    second = first;
                    first = {col, ans};
                } else if (second.index == -1 || ans <= second.value) {
                    second = {col, ans};
                }

                grid[row][col] += ans;
            }

            firstMin = first;
            secondMin = second;
        }

        return firstMin.value;
    }
};
