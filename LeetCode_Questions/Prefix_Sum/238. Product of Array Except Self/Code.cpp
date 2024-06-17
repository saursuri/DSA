/*
Problem Link: https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150
Time ComplexitY: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        int product = 1;
        for(int i=0; i<n; i++)
        {
            ans[i] = product;
            product *= nums[i];
        }

        product = 1;
        for(int i=n-1; i>=0; i--)
        {
            ans[i] *= product;
            product *= nums[i];
        }

        return ans;
    }
};
