/*
Problem Link: https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09
Time Complexity: O(rows * cols)
Space Complexity: O(3 * 3)
*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (rows < 3 || cols < 3) return 0;

        int ans = 0;
        for (int r = 0 ; r < rows - 2; r++)
        {
            for (int c = 0; c < cols - 2; c++)
            {
                // Col Sum
                unordered_set<int> mp;
                bool Flag = false;
                int colSum[3] = {0, 0, 0};
                for (int j = c; j < c + 3; j++)
                {
                    int k = 0;
                    for (int i = r; i < r + 3; i++)
                    {
                        if (mp.count(grid[i][j]) || grid[i][j] > 9 || grid[i][j] < 1)
                            Flag = true;
                        else
                            mp.insert(grid[i][j]);

                        colSum[k++] += grid[i][j];
                    }
                }

                if (Flag) continue;

                if (colSum[0] != colSum[1] || colSum[1] != colSum[2])
                    continue;

                // Row Sum
                int rowSum[3] = {0, 0, 0};
                for (int j = r; j < r + 3; j++)
                {
                    int k = 0;
                    for (int i = c; i < c + 3; i++)
                    {
                        rowSum[k++] += grid[j][i];
                    }
                }

                if (rowSum[0] != rowSum[1] || rowSum[1] != rowSum[2] || colSum[0] != rowSum[0])
                    continue;

                // Diagnol Sum 1
                int digSum1 = 0;
                for (int i=0; i<3; i++)
                {
                    digSum1 += grid[i+r][i+c];
                }

                // Diagnol Sum 2
                int digSum2 = 0, j=2;
                for (int i=0; i<3; i++)
                {
                    digSum2 += grid[i+r][j+c];
                    j--;
                }

                if (digSum1 != digSum2 || digSum1 != rowSum[0])
                    continue;
                
                ans++;

            }
        }

        return ans;
    }
};
