/*
Problem Link: https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n);
Space Complexity: O(1)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.begin() + n-k);
        reverse(nums.begin() + n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
