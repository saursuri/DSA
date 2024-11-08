/*
Problem Link: https://leetcode.com/problems/maximum-xor-for-each-query/description/?envType=daily-question&envId=2024-11-08
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int num = pow(2, maximumBit) - 1;
        int n = nums.size();

        for(int i=1; i<n; i++)
        {
            nums[i] ^= nums[i-1]; 
        }

        reverse(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            nums[i] ^= num; 
        }

        return nums;


    }
};
