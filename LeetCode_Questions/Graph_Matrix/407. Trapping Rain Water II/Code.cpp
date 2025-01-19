/*
Problem Link: https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-01-19
Time Complexity: O(m*n*log(m+n))
Space Complexity: O(m*n)
*/
struct ds{
    int height;
    int row;
    int col;
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        auto compare = [](ds &d1, ds &d2){
            return d1.height > d2.height;
        };

        priority_queue<ds, vector<ds>, decltype(compare)> pq(compare);
        vector<vector<bool>> visited(m, vector<bool>(n,false));

        // Push borders
        for(int row=0; row<m; row++)
        {
            pq.push({heightMap[row][0], row, 0});
            pq.push({heightMap[row][n-1], row, n-1});
            visited[row][0] = true;
            visited[row][n-1] = true;
        }
        // Push Borders
        for(int col=0; col<n; col++)
        {
            pq.push({heightMap[0][col], 0, col});
            pq.push({heightMap[m-1][col], m-1, col});
            visited[0][col] = true;
            visited[m-1][col] = true;
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        int waterAccumulated = 0;
        while(!pq.empty())
        {
            ds data = pq.top();
            pq.pop();

            for(int i=0; i<4; i++)
            {
                int nRow = data.row + dr[i];
                int nCol = data.col + dc[i];

                if (0 <= nRow && nRow < m && 0 <= nCol && nCol < n && !visited[nRow][nCol])
                {
                    waterAccumulated += max(data.height - heightMap[nRow][nCol], 0);
                    visited[nRow][nCol] = true;
                    pq.push({max(data.height,heightMap[nRow][nCol]),nRow,nCol});
                }
            }

        }

        return waterAccumulated;

    }
};
