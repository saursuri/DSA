/*
Problem Link: https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22
Time complexity: O(m*n)
Space complexity: O(m*n)
*/

class Solution {
public:

    void traverseUsingBFS(vector<vector<int>>& isWater, vector<vector<int>>& outputMatrix,queue<pair<int,int>>&q)
    {   
        int m = isWater.size();
        int n = isWater[0].size();

        // Row-1 --> North, Row+1 --> South
        int delRow[] = {0,0,-1,1};
        // Col-1 --> East, Col+1 --> West
        int delCol[] = {-1,1,0,0};

        while(!q.empty())
        {
            int rowCor = q.front().first;
            int colCor = q.front().second;

            // pop the element
            q.pop();

            // Standing at a node, Move in all 4 directions
            for(int index=0; index<4; index++)
            {   
                int chanRow = rowCor + delRow[index];
                int chanCol = colCor + delCol[index];

                if(0<=chanRow && 0<=chanCol && chanRow<m && chanCol<n && outputMatrix[chanRow][chanCol]>1+outputMatrix[rowCor][colCor])
                {   
                    outputMatrix[chanRow][chanCol] = 1 + outputMatrix[rowCor][colCor];

                    // Push the node to visit in future
                    q.push({chanRow,chanCol});
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        // Output matrix in which answer will be stored
        vector<vector<int>> outputMatrix(m,vector<int>(n,INT_MAX));
        
        // Maintain a Queue
        queue<pair<int,int>> q;

        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(isWater[row][col]==1)
                {
                    outputMatrix[row][col] = 0;
                    // Push the row and col of Water to Queue
                    q.push({row,col});
                }

            }
        }

        traverseUsingBFS(isWater,outputMatrix,q);

        return outputMatrix;
    }
};
