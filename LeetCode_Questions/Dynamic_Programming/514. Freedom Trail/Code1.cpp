/*
Problem Link: https://leetcode.com/problems/freedom-trail/description/?envType=daily-question&envId=2024-04-27
Time Complexity: O(m*n)
Space Complexity: O(m*n) + Recursion Stack
*/

class Solution {
private:
    int findRotateStepsUtil(int ringIndex, int keyIndex, string& ring,
                            string& key, vector<vector<int>>& dp) {
        int m = ring.length();
        int n = key.length();
        if (keyIndex == n)
            return 0;

        int ans = 0;
        if (dp[ringIndex][keyIndex] != -1)
            return dp[ringIndex][keyIndex];

        // If character on ring matches with key character
        if (ring[ringIndex] == key[keyIndex]) {
            ans +=
                1 + findRotateStepsUtil(ringIndex, keyIndex + 1, ring, key, dp);
        } else {
            int index = ringIndex, steps = 0;
            // Rotate dial clockWise till key doesn't match
            while (ring[index] != key[keyIndex]) {
                index = (index + m - 1) % m;
                steps++;
            }

            int clockWise =
                steps + findRotateStepsUtil(index, keyIndex, ring, key, dp);
            index = ringIndex, steps = 0;
            // Rotate dial antiClockWise till key doesn't match
            while (ring[index] != key[keyIndex]) {
                index = (index + 1) % m;
                steps++;
            }
            int antiClockWise =
                steps + findRotateStepsUtil(index, keyIndex, ring, key, dp);
            ans += min(clockWise, antiClockWise);
        }
        return dp[ringIndex][keyIndex] = ans;
    }

public:
    int findRotateSteps(string ring, string key) {
        int m = ring.length();
        int n = key.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findRotateStepsUtil(0, 0, ring, key, dp);
    }
};
