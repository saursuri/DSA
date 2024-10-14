/*
Problem Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2024-10-14
Time Complexity: O(klogn)
Space Complexity: O(n)
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int> pq;

        for (auto &it: nums) pq.push(it);
        long long score = 0;
        while(k--)
        {
            int pqTop = pq.top();
            pq.pop();

            score += pqTop;
            pq.push(ceil(double(pqTop)/3));
        }

        return score;
    }
};
