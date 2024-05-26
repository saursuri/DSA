/*
Problem Link: https://leetcode.com/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-05-26
Time Complexity: O(6n) --> n is the number of days 3 is max consecutive late Count and 2 is absent count
Space Complexity: O(6n) 
*/
class Solution {
    int n;
    int modulo;
    int checkRecordUtil(int days, int lateCount, int absentCount,
                        vector<vector<vector<int>>>& dp) {
        if (days == n)
            return 1;

        int ans = 0;

        if (dp[days][lateCount][absentCount] != -1)
            return dp[days][lateCount][absentCount];

        // If present on the current day
        ans = (ans + checkRecordUtil(days + 1, 0, absentCount, dp)) % modulo;

        if (lateCount < 2) {
            // If late on the current day
            ans = (ans +
                   checkRecordUtil(days + 1, lateCount + 1, absentCount, dp)) %
                  modulo;
        }

        if (absentCount < 1) {
            // If absent on the current day
            ans = (ans + checkRecordUtil(days + 1, 0, absentCount + 1, dp)) %
                  modulo;
        }

        return dp[days][lateCount][absentCount] = ans % modulo;
    }

public:
    int checkRecord(int n) {
        this->n = n;
        this->modulo = 1e9 + 7;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(3, vector<int>(2, -1)));
        return checkRecordUtil(0, 0, 0, dp);
    }
};
