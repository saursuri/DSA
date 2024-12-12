/*
Problem Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(auto &it: gifts) pq.push(it);

        while(k>0)
        {
            int top = pq.top();
            pq.pop();

            pq.push(sqrt(top));

            k--;
        }

        long long ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
