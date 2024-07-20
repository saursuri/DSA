/*
Problem Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector<int>(n));

        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                ans[row][col] = min(rowSum[row], colSum[col]);
                rowSum[row] -= ans[row][col];
                colSum[col] -= ans[row][col];
            }
        }

        return ans;

    }
};
