/*
Problem Link: https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25
Time Complexity: O(n)
Space Complexity: O(26)
*/
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();

        // Character array 0-->26 chars
        // Used to store longest subsequence of ending at each char
        vector<int> dp(26, 0);
        int result = 0;
        for (int index = 0; index < n; index++) {
            // Current index of the character
            int currIndex = s[index] - 'a';
            // Max subsequence can be generated by taking current max
            // subsequence in rangle of currIndex-k --> currIndex+k
            int left = max(0, currIndex - k);
            int right = min(25, currIndex + k);

            int longestSequence = 0;
            for (int j = left; j <= right; j++) {
                longestSequence = max(longestSequence, dp[j]);
            }

            // Update the currIndex with updated longest subsequence
            dp[currIndex] = max(longestSequence + 1, dp[currIndex]);
            // Store to the result
            result = max(result, dp[currIndex]);
        }
        return result;
    }
};
