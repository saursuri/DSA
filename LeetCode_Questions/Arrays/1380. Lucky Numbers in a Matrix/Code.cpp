/*
Problem Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19
Time Complexity: O(M*N)
Space Complexity: O(M+N)
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> min_rows(m,INT_MAX);
        vector<int> max_cols(n,0);

        for(int rows=0; rows<m; rows++)
        {

            for(int cols=0; cols<n; cols++)
            {
                min_rows[rows] = min(min_rows[rows], matrix[rows][cols]);
                max_cols[cols] = max(max_cols[cols], matrix[rows][cols]);
            }

        }

        for (int row_ind = 0; row_ind < m; ++row_ind) {
            for (int col_ind = 0; col_ind < n; ++col_ind) {
                int el = matrix[row_ind][col_ind];
                if (el == min_rows[row_ind] && el == max_cols[col_ind]) {
                    return {el};
                }
            }
        }

        return {};
    }
};
