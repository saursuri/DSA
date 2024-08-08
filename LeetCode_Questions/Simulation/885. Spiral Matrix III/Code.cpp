/*
Problem Link: https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08
Time Complexity: O(rows*cols)
Space Complexity: O(rows*cols)
*/
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        /*
        Right, Down, Left, Up
        */

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        vector<vector<int>> ans;

        int count = rows * cols;
        int r = rStart, c = cStart;
        int i = -1;
        while(count)
        {
            if (0 <= r && r < rows && 0 <= c && c < cols && matrix[r][c] == 0)
            {
                matrix[r][c] = 1;
                ans.push_back({r,c});
                count--;
            }

            int j = (i+1) % 4;
            int chR = r + dr[j];
            int chC = c + dc[j];

            if (0 <= chR && chR < rows && 0 <= chC && chC < cols && matrix[chR][chC] == 1)
            {
                r = r + dr[i];
                c = c + dc[i];
            }
            else
            {
                i = j;
                r = chR;
                c = chC;
            }

        }

        return ans;
    }
};
