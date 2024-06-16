/*
Problem  Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int buyPrice = prices[0];

        int indx = 0;
        int totalProfit = 0;
        while(indx < n)
        {
            // Sell when profit at next day will be less
            if (indx == n-1 || prices[indx + 1] < prices[indx])
            {
                totalProfit += prices[indx] - buyPrice;
                buyPrice = (indx == n-1) ? 0 : prices[indx + 1];
            }
            
            indx++;
        }

        return totalProfit;
    }
};
