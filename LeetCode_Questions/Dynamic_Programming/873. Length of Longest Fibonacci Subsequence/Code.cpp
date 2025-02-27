/*
Problem Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;  // Stores index of each number
        vector<vector<int>> dp(n, vector<int>(n, 2)); // DP table initialized to 2
        int maxLen = 0;

        // Store indices of elements for fast lookup
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Iterate over pairs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int prev = arr[i] - arr[j]; 
                if (prev < arr[j] && index.count(prev)) {
                    int k = index[prev]; // Get index of `prev`
                    dp[j][i] = dp[k][j] + 1; // Extend the sequence
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
        }

        return (maxLen >= 3) ? maxLen : 0;
    }
};
