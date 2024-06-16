/*
Problem Link: https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
Approach: Using Extra Space
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;

        vector<int> numsCopy(n);

        int i = 0;
        for (int indx = n-k; indx < n; indx++)
        {
            numsCopy[i] = nums[indx];
            i++;
        }

        for (int indx = 0; indx < n-k; indx++)
        {
            numsCopy[i] = nums[indx];
            i++;
        }

        for (int indx=0; indx<n; indx++)
        {
            nums[indx] = numsCopy[indx];
        }
    }
};
