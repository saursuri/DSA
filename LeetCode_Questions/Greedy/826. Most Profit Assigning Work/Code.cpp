/*
Problem Link: https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
Time Complexity: O(nlogn + mlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vec;

        int n = difficulty.size();
        for(int i=0; i<n; i++)
        {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());

        int m = worker.size();
        int ans = 0;
        int indx = 0, mx = 0;

        for(int i=0; i<m; i++)
        {
            while (indx < n && worker[i] >= vec[indx].first)
            {
                mx = max(mx, vec[indx].second);
                indx++;
            }

            ans += mx;
        }

        return ans;

    }
};
