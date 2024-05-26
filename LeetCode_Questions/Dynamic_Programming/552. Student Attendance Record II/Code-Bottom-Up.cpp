/*
Problem Link: https://leetcode.com/problems/student-attendance-record-ii/description/
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int checkRecord(int n) {
        int modulo = 1e9 + 7;

        // Bottom-up DP
        int dp[n+1][2][3];

        // Base Case
        for (int absent = 0; absent < 2; absent++) {
            for (int late = 0; late < 3; late++) {
                dp[0][absent][late] = 1;
            }
        }

        for (int days = 1; days <= n; days++) {
            for (int absent = 0; absent < 2; absent++) {
                for (int late = 0; late < 3; late++) {

                    long result = dp[days - 1][absent][0];
                    result += (late + 1 < 3 ? dp[days - 1][absent][late + 1] : 0); 
                    result += (absent + 1 < 2 ? dp[days - 1][absent + 1][0] : 0);

                    dp[days][absent][late] = result % modulo;
                }
            }
        }

        return dp[n][0][0];
    }
};
