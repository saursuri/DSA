/*
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minBuy = prices[0];
        int maxProfit = 0;
        int indx = 0;

        while (indx < n-1)
        {
            minBuy = min(minBuy, prices[indx]);
            maxProfit = max(maxProfit, prices[indx+1] - minBuy);
            indx++;
        }

        return maxProfit;
    }
};
