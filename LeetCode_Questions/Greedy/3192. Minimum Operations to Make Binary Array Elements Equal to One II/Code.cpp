/*
Problem Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        
        int flips = 0;
        for (int i=0; i<n; i++)
        {
            if (nums[i] == 0 && flips % 2 == 0)
            {
                flips++;
            }
            
            if (nums[i] == 1 && flips % 2 == 1)
            {
                flips++;
            }
        }
        
        return flips;
        
    }
};
