/*
Problem Link: https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n,1);

        for (int i=1; i<n; i++)
        {
            if (ratings[i] > ratings[i-1])
            {
                candies[i] = candies[i-1] + 1;
            }

        }

        for (int i=n-1; i>0; i--)
        {
            if (ratings[i-1] > ratings[i])
            {
                candies[i-1] = max(candies[i-1], candies[i] + 1);
            }
        }

        int ans = 0;
        for(auto it: candies)
        {
            ans += it;
        }
        return ans;
    }
};
