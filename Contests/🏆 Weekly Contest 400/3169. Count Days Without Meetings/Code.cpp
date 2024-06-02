/*
Problem Link: https://leetcode.com/problems/count-days-without-meetings/description/
Approach: Merge Intervals + Sorting + Greedy
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compare);
        int n = meetings.size();

        int ans = 0;
        int lastMeetingEnd = 0;
        for (int i=0; i<n; i++)
        {
            lastMeetingEnd = max(lastMeetingEnd, meetings[i][1]);

            if (meetings[i][1] > days) break;

            if (i != n-1 && lastMeetingEnd < meetings[i+1][0]) 
                ans += meetings[i+1][0] - lastMeetingEnd - 1;
        }

        return ans + days - lastMeetingEnd + meetings[0][0] - 1 ;
    }
};
