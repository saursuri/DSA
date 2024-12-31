/*
Problem Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=daily-question&envId=2024-12-31
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1); // Memoization array
        
        // Helper function to find the next day index not covered by the current pass
        auto nextIndex = [&](int indx, int duration) {
            int endDay = days[indx] + duration - 1;
            int i = indx;
            while (i < n && days[i] <= endDay) {
                i++;
            }
            return i;
        };
        
        // Recursive function with memoization
        function<int(int)> solve = [&](int indx) {
            if (indx >= n) return 0; // Base case: no more days to cover
            
            if (dp[indx] != -1) return dp[indx]; // Return memoized result
            
            // Calculate the minimum cost considering all three pass options
            int pass1 = costs[0] + solve(nextIndex(indx, 1));
            int pass2 = costs[1] + solve(nextIndex(indx, 7));
            int pass3 = costs[2] + solve(nextIndex(indx, 30));
            
            return dp[indx] = min({pass1, pass2, pass3});
        };
        
        return solve(0); // Start recursion from the first day
    }
};
