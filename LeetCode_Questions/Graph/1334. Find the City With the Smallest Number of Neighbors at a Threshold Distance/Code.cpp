/*
Problem Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=daily-question&envId=2024-07-26
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Apply flyod Warshall algo
        // Create adjMatrix
        vector<vector<int>> adjMatrix(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++)
        {
            adjMatrix[i][i] = 0;
        }

        for(auto it:edges)
        {
            adjMatrix[it[0]][it[1]] = it[2];
            adjMatrix[it[1]][it[0]] = it[2];
        }

        for(int via=0; via<n; via++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(adjMatrix[i][via]==1e9 || adjMatrix[via][j]==1e9) continue;
                    adjMatrix[i][j] = min(adjMatrix[i][j],adjMatrix[i][via]+adjMatrix[via][j]);
                }
            }
        }

        int city = -1;
        int countMax = n;
        for(int row=0;row<n;row++)
        {
            int count = 0;
            for(int col=0;col<n; col++)
            {
                if(adjMatrix[row][col]<=distanceThreshold)
                {
                    count++;
                }

            }
            if (count<=countMax)
            {
                countMax = count;
                city = row;
            }
        }

        return city;
    }
    
};
