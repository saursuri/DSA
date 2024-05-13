/*
Problem Link: https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));

        for(int row=0; row<n-2; row++)
        {
            for(int col=0; col<n-2; col++)
            {
                int maxElem = 0;
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        maxElem = max(maxElem, grid[row+i][col+j]);
                    }
                }
                ans[row][col] = maxElem;
            }
        }

        return ans;
    }

};
