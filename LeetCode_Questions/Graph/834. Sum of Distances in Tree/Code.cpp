/*
Problem Link: https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28
Time Complexity: O(n+n) --> 2 DFS
Space Complexity: O(n+e) --> Nodes + Edges for adjList
*/
class Solution {
private:
    int calUsingDFS(int node, vector<int> adjList[], vector<int> &visited, int &sum, int height, vector<int> &childCount)
    {
        // Mark as visited
        visited[node] = 1;

        sum += height;
        // All childs of node including currNode
        int child = 1;
        for(auto neighbor: adjList[node])
        {
            if(!visited[neighbor])
                child += calUsingDFS(neighbor, adjList, visited, sum, height+1, childCount);
        }
        childCount[node] = child;

        return child;

    }

    void computeAnsUsingDFS(int node, vector<int> adjList[], vector<int> &visited, vector<int> &sum, vector<int> &childCount)
    {
        int n = visited.size();

        // Mark as Visited
        visited[node] = 1;

        for(auto neighbor: adjList[node])
        {
            if(!visited[neighbor])
            {
                // This formula is computed form dry Run
                // Important step
                sum[neighbor] = sum[node] + n - 2*childCount[neighbor];
                computeAnsUsingDFS(neighbor, adjList, visited, sum, childCount);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adjList[n];

        for(auto it: edges)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<int> childCount(n,0);
        vector<int> visited(n,0);
        vector<int> resultSum(n,0);
        int height = 0;
        calUsingDFS(0, adjList, visited, resultSum[0], height, childCount);

        vector<int> vis(n,0);
        computeAnsUsingDFS(0, adjList, vis, resultSum, childCount);

        return resultSum;
    }
};
