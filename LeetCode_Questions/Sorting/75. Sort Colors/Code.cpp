/*
Problem Link: https://leetcode.com/problems/sort-colors/description/
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) mid++; // Mid element increased
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        
    }
};
