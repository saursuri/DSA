/*
Problem Link: https://leetcode.com/problems/find-eventual-safe-states/?envType=daily-question&envId=2025-01-24
Time Complexity: O(V+E)
Space Complexity: O(V)
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size(); // No of nodes
        vector<int> safeNodes;

        queue<int> q; // Push nodes with indegree 0
        vector<int> indegree(n,0);
        vector<vector<int>> adjList(n); // To reverse the graph

        for (int node=0; node<n; node++)
        {
            for (auto &nbr: graph[node])
            {
                indegree[node]++;
                adjList[nbr].push_back(node);
            }
        }

        for (int node=0; node<n; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            // Neighbors
            for (auto &nbr: adjList[node])
            {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;

    }
};
