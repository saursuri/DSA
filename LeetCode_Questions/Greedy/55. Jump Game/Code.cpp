/*
Problem Link: https://leetcode.com/problems/jump-game/description/
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // Goal is to reach the last Index
        int goal = n-1;
        for (int index=n-1; index>=0; index--)
        {
            // If from current index can reach the goal
            if (index + nums[index] >= goal)
            {
                // Update the Goal to reach the current Index
                goal = index;
            }
        }

        return goal==0;
    }
};
