/*
Problem Link: https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21
Time Complexity: O(k + m + n)
Space Complexity: O(k^2 + m + n)*/
class Solution {
private:
    unordered_map<int, int> topo_sort(vector<int> adjList[], int n) {
        unordered_map<int, int> mp;
        vector<int> indegree(n, 0);

        for (int node = 0; node < n; node++) {
            for (auto &it : adjList[node]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        int i = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            mp[node] = i++;

            for (auto &nbr : adjList[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If we couldn't process all nodes, there was a cycle
        if (i != n) {
            return {};
        }

        return mp;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        vector<int> adjList1[k];
        for (auto &it : rowConditions) {
            int u = it[0] - 1; // Adjusting index to be 0-based
            int v = it[1] - 1; // Adjusting index to be 0-based
            adjList1[u].push_back(v);
        }

        vector<int> adjList2[k];
        for (auto &it : colConditions) {
            int u = it[0] - 1; // Adjusting index to be 0-based
            int v = it[1] - 1; // Adjusting index to be 0-based
            adjList2[u].push_back(v);
        }

        unordered_map<int, int> rows = topo_sort(adjList1, k);
        unordered_map<int, int> cols = topo_sort(adjList2, k);

        // If we detected a cycle in either rows or cols, return an empty matrix
        if (rows.empty() || cols.empty()) {
            return {};
        }

        for (auto &it : rows) {
            int row = it.second;
            int col = cols[it.first];
            matrix[row][col] = it.first + 1; // Adjusting index back to 1-based
        }

        return matrix;
    }
};
