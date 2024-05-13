/*
Problem Link: https://leetcode.com/problems/score-after-flipping-matrix/description/?envType=daily-question&envId=2024-05-13
Time Complexity: O(mn)
Space Complexity: O(mn) --> Size of the input grid
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int result=pow(2,n-1)*m;
        
        for (int col=1; col<n; col++)
        {
            int noOfOnes = 0;
            for (int row=0; row<m; row++)
            {
                if (grid[row][0]==0 && grid[row][col]==0 ||
                grid[row][0]==1 && grid[row][col]==1)
                    noOfOnes++;
            }

            int noOfZeros = m-noOfOnes;
            if (noOfOnes<noOfZeros)
                result += pow(2,n-col-1)*noOfZeros;
            else
                result += pow(2,n-col-1)*noOfOnes;
        }

        return result;
    }
};
