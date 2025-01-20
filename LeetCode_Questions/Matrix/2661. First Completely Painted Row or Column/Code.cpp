/*
Problem Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20
Time Complexity: O(m*n + k)
Space Complexity: (m*n)
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size();

        unordered_map<int,int[2]> hashMap;
        vector<int> rowCount(m,n);
        vector<int> colCount(n,m);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                hashMap[mat[i][j]][0] = i;
                hashMap[mat[i][j]][1] = j;
            }
        }

        for(int i=0; i<arr.size(); i++)
        {
            int arrVal = arr[i];
            auto [row, col] = hashMap[arrVal];

            if (--rowCount[row]==0 || --colCount[col]==0)
                return i;
        }

        return -1;        
    }
};
