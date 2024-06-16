/*
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int indx1 = 1, indx2 = 1;

        while (indx1 < n)
        {
            if (nums[indx1-1] != nums[indx1])
            {
                nums[indx2] = nums[indx1];
                indx2++;
            }

            indx1++;
        }

        return indx2;
    }
};
