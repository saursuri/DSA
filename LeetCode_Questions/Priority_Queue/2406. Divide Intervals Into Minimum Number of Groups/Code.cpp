/*
Problem Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        auto func = [&](vector<int>a, vector<int>b){
            if (a[0] == b[0]) return a[1] < a[1];
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), func);

        // [1,5] [1,10] [2,3] [5,10] [6,8]
        priority_queue<int, vector<int>, greater<int>> end;

        int ans = 0;
        for (auto &it: intervals)
        {
            if (end.size() > 0 && end.top() < it[0])
            {
                end.pop();
            }

            end.push(it[1]);

        }

        return end.size();
    }
};
