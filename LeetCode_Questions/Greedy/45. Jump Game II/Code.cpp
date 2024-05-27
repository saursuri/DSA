/*
Problem Link: https://leetcode.com/problems/jump-game-ii/description/
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        int left = 0, right = 0;
        int jumps = 0;
        while (right < n-1)
        {
            int farthest=0;
            // Check the current range and check farthest 
            // we can reach, update the right index to the
            // farthest
            for (int index=left; index<=right; index++)
            {
                farthest = max(index + nums[index], farthest);
            }
        
            jumps++;
            left = right + 1;
            right = farthest;

        }

        return jumps;
    }
};
