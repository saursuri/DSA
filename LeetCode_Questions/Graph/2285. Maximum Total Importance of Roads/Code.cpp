/*
Problem Link: https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Optimize I/O operations (generally useful in competitive programming)
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int degree[n];
        memset(degree, 0, sizeof(degree));

        // Calculate the degree of each node
        for (const auto &r : roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }

        // Vector to store the sorted indices based on their degree
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort the indices based on the degree in descending order
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return degree[a] < degree[b];
        });

        // Assign importance values
        vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[indices[i]] = i + 1;
        }

        // Calculate the total importance
        long long ans = 0;
        for (const auto& r : roads) {
            ans += importance[r[0]] + importance[r[1]];
        }

        return ans;
    }
};
