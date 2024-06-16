/*
Problem Link: https://leetcode.com/problems/patching-array/description/?envType=daily-question&envId=2024-06-16
Time Complexity: max(O(length of the nums array), O(log(n)))
Space Complexity: O(1)
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long currentRange = 0;
        int patches = 0;
        int indx = 0;
        while(currentRange < n)
        {

            if (indx < nums.size() && (currentRange + 1 >= nums[indx]))
            {
                currentRange += nums[indx];
                indx++;

            }
            else
            {
                currentRange = currentRange*2 + 1;
                patches++;
            }
        }

        return patches;
    }
};
