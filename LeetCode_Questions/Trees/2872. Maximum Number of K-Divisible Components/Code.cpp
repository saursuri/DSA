/*
Problem Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/?envType=daily-question&envId=2024-12-21
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
private:
    int k;
    long nodeSum[30000];
    long dfs(vector<int> adjList[], int node, vector<int> &visited, int &splits, vector<int> &values)
    {
        // Mark node as visited
        visited[node] = 1;

        // Visit neighbors
        for (auto &it: adjList[node])
        {
            if (visited[it] == 0)
            { 
                nodeSum[node] += dfs(adjList, it, visited, splits, values);
            }
        }

        if (nodeSum[node] % k == 0)
        {
            splits++;
            return 0; // No nodeSum returned from the leaf
        }

        return nodeSum[node];
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;

        for(int i=0; i<n; i++)
        {
            nodeSum[i] = values[i];
        }

        vector<int> adjList[n];

        for(auto &it: edges)
        {
            int u = it[0];
            int v = it[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visited(n,0);
        int splits = 0;
        dfs(adjList, 0, visited, splits, values);

        return splits;

    }
};
