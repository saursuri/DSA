/*
Problem Link: https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxReach = nums[0];

        int indx = 0, n = nums.size();

        while (indx < n)
        {
            if (maxReach < indx)
                return false;

            if (maxReach < indx + nums[indx])
                maxReach = indx + nums[indx];
            
            indx++;
        }

        return true;
    }
};
