/*
Problem Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2024-05-09
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int n = happiness.size();
        long long sum = 0, count=0;
        for (int i=0; i<n; i++)
        {
            int val = happiness[i] - count;
            if (k>0)
            {
                sum += val>0?val:0;
                count++;
                k--;
            }
            else
                break;
        }

        return sum;
    }
};
