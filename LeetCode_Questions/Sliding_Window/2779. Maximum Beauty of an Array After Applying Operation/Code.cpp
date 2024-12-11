/*
Problem Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11
Time Complexity: O(n*logn)
Space Complexity: O(1)
*/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int left = 0, right = 0;
        int maxWindow = 0;

        while(right<n)
        {
            while(nums[right] - nums[left] > 2 * k)
            {
                // Shrink the window
                left++;
            }

            maxWindow = max(maxWindow, right-left+1);

            right++;
        } 

        return maxWindow;
    }
};
