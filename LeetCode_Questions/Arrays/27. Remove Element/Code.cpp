/*
Problem Link: https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int indx1 = 0, indx2 = 0;

        while (indx1 < n)
        {
            if (nums[indx1] != val)
            {
                nums[indx2] = nums[indx1];
                indx2++;
            }

            indx1++;
        }

        return indx2;
    }
};
