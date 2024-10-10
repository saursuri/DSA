/*
Problem Link: https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> rightMax(n,0);
        rightMax[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--)
        {
            rightMax[i] = max(nums[i], rightMax[i+1]);
        }

        int i=0, j=0, ramp=0;
        while(j<n)
        {
            while (i<j && nums[i] > rightMax[j]) i++;
            ramp = max(ramp, j-i);

            j++;
        }

        return ramp;
    }
};
