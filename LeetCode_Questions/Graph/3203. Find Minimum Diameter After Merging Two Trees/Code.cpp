/*
Problem Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/?envType=daily-question&envId=2024-12-24
Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
int findDiameter(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;

    // Graph
    vector<int> adjList[n];
    vector<int> indegree(n,0);

    for (auto &it: edges)
    {
        int u = it[0];
        int v = it[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        indegree[u]++, indegree[v]++;
    }

    queue<int> q;

    for(int node=0; node<n; node++)
    {
        if (indegree[node] == 1)
            q.push(node);
    }

    int level = 0, nodesLeft = n;

    while(nodesLeft > 2)
    {
        int qSize = q.size();
        // Remove Corner nodes
        nodesLeft -= qSize;

        for (int i=0; i<qSize; i++)
        {
            int node = q.front();
            q.pop();

            // Neigboring node
            for (auto &nbr: adjList[node])
            {
                // Decrease indegree
                indegree[nbr]--;
                if (indegree[nbr] == 1)
                    q.push(nbr);
            }
        }

        level++;
    }

    return (nodesLeft==2)?2*level+1:2*level;
}

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        int d1 = findDiameter(edges1);
        int d2 = findDiameter(edges2);
        int ans = max(max(d1, d2), (d1+1)/2 + 1 + (d2+1)/2);
        return ans;
    }
};
