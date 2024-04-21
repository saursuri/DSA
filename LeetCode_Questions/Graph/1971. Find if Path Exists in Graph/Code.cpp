/*
Problem Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> adjList[n];

        // Create adjList
        for(auto edge: edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // Queue for BFS Traversal
        queue<pair<int,int>> q;
        q.push({0,source});

        vector<int> distance(n,1e9);
        distance[source] = 0; 

        // Perform BFS Traversal
        while(!q.empty())
        {
            auto elem = q.front();
            q.pop();

            int node = elem.second;
            int dis = elem.first;

            // Visit neighbors
            for(auto neighbor: adjList[node])
            {
                int adjNode = neighbor;

                if(distance[adjNode]>dis+1)
                {
                    distance[adjNode]=dis+1;
                    q.push({distance[adjNode],adjNode});
                }
            }
        }

        if (distance[destination]==1e9) return false;
        else return true;
    }
};
