/*
Problem Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/


class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (auto &it: nums)
        {
            pq.push(it);
        }

        int ops = 0;
        while (!pq.empty())
        {
            ll pqTop = pq.top();
            pq.pop();

            if (pqTop >= k) return ops;
            
            if (!pq.empty())
            {
                ll pqSecond = pq.top();
                pq.pop();

                ll toPush = (ll)min(pqTop, pqSecond)*2 + (ll)max(pqTop,pqSecond);
                pq.push(toPush);
                ops++;
            }
        }


        return -1;
        
    }
};
