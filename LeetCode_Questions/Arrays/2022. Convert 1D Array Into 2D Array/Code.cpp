/*
Problem Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        if (m*n < original.size() || original.size() < m*n) return ans;

        ans.resize(m, vector<int>(n,0));

        int indx=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans[i][j] = original[indx++]; 
            }
        }

        return ans;
    }
};
