#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int count = 0;
        int minLoss = INT_MAX;

        for (ll num:nums)
        {
            if ((num^k)>num)
            {
                count++;
                sum += num^k;
            }
            else 
            {
                sum += num;
            }

            minLoss = min((ll)minLoss,abs(num-(num^k)));
        }

        // If count is even that means ideal sum can be achieved
        if (count%2==0) return sum;
        // If ideal sum can't be achieved, then remove the minLoss from the sum
        else return sum-minLoss;
    }
};
