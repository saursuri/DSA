/*
Problem Link: https://leetcode.com/problems/minimum-height-trees/description/?envType=daily-question&envId=2024-04-23
Tag: Topological Sort, BFS
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1) return {0};

        // Create adjList
        vector<int> adjList[n];

        // In-degree of n nodes is initialized to 0
        vector<int> indegree(n,0);
        for(auto edge: edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        // Push nodes to Queue with indegree as 1
        queue<int> q;
        for(int node=0; node<n; node++)
        {
            if(indegree[node]==1)
                q.push(node);
        }

        // While n is greater than 2
        // Because at max 2 nodes will be the ans
        while(n>2)
        {
            int qSize = q.size();
        
            // Nodes will decrease by qSize
            n-=qSize;

            for(int i=0; i<qSize; i++)
            {
                int node = q.front();
                q.pop();

                // Visit neighbors
                for(auto neighbor: adjList[node])
                {
                    // Remove indegree of neighbors
                    indegree[neighbor]--;

                    // If indegree becomes that means that became a leaf
                    // node
                    if(indegree[neighbor]==1)
                        q.push(neighbor);
                }
            }

        }

        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
