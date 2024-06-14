/*
Problem Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int count = 0;
        for(int i=1; i<n; i++)
        {
            if (nums[i-1] >= nums[i])
            {
                count += abs(nums[i] - nums[i-1]) + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return count;
    }
};
