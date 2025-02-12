/*
Problem Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/?envType=daily-question&envId=2025-02-12
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
    int find_indx(int num)
    {
        int sum = 0;

        while(num)
        {
            sum += (num%10);
            num /= 10;
        }

        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {

        int n = nums.size();
        priority_queue<int> pq[100];

        // O(nlogn)
        for (int i=0; i<n; i++)
        {
            int indx = find_indx(nums[i]);

            pq[indx].push(nums[i]);
        }

        int maxAns = -1;
        // O(100)
        for (int i=0; i<100; i++)
        {

            if (pq[i].size() > 1)
            {
                int localAns = 0;
                localAns += pq[i].top();
                pq[i].pop();
                localAns += pq[i].top();
                maxAns = max(maxAns, localAns);
            }

        }

        return maxAns;
    }
};
