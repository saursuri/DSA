/*

Problem Link: https://leetcode.com/problems/range-product-queries-of-powers/description/?envType=daily-question&envId=2025-08-11
Time Complexity: O(32 x 10^5)
Space Complexity: O(32)

*/
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> nums;
        int counter = 0;
        int MOD = 1e9 + 7;
        while(n)
        {
            if (n & 0x1)
                nums.push_back(0x1 << counter);

            // Keep right shifting
            n = n >> 1;
            counter++;
        }

        vector<int> ans;

        for (auto &it: queries)
        {
            long long local_ans = 1;
            for (int i=it[0]; i<=it[1]; i++)
            {
                local_ans = ( local_ans * nums[i] ) % MOD;
            }
            ans.push_back(int(local_ans));
        }

        return ans;
    }
};
