/*
Tags: BFS + Dijkstra
Problem Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2024-05-15
Time Complexity: O(n^2logn)
Space Complexity: O(n^2)
*/
class Elements
{
    public:
        int safeFactor;
        int row;
        int col;

        // Define comparison operator for priority_queue
        bool operator<(const Elements& other) const {
            return safeFactor < other.safeFactor;
        }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        queue<pair<int,int>> q;
        vector<vector<int>> safeGrid(n,vector<int>(n,1e9));
        vector<vector<int>> visited(n,vector<int>(n,0));

        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if (grid[row][col]==1)
                {
                    q.push({row,col});
                    safeGrid[row][col] = 0;
                }
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        int depth = 1;
        while(!q.empty())
        {
            int qSize = q.size();

            for(int i=0; i<qSize; i++)
            {
                auto frontElem = q.front();
                q.pop();

                // Visit neighbors
                for(int index=0; index<4; index++)
                {
                    int uRow = frontElem.first + dr[index];
                    int uCol = frontElem.second + dc[index];

                    if (0<=uRow && uRow<n && 0<=uCol && uCol<n
                    && grid[uRow][uCol]==0 && !visited[uRow][uCol])
                    {
                        safeGrid[uRow][uCol] = depth;
                        visited[uRow][uCol] = 1;
                        q.push({uRow,uCol});

                    }
                }
            }

            // Increase depth
            depth++;
        }

        vector<vector<int>> vis(n,vector<int>(n,0));

        priority_queue<Elements> pq;
        pq.push({safeGrid[0][0], 0, 0});
        vis[0][0] = 1;

        while(!pq.empty()){
            auto elements = pq.top();
            pq.pop();

            if(elements.row == n - 1 && elements.col == n - 1) return elements.safeFactor;

            for(int i = 0; i < 4; i++) {
                int uRow = elements.row + dr[i];
                int uCol = elements.col + dc[i];

                if(uRow >= 0 && uRow < n && uCol >= 0 && uCol < n && !vis[uRow][uCol]){
                    int s = min(elements.safeFactor, safeGrid[uRow][uCol]);
                    pq.push({s, uRow, uCol});
                    vis[uRow][uCol] = 1;
                }
            }
        }

        return -1;

    }
};
