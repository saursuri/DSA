/*
Problem Link: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n <= 4) return 0;

        int option1 = min(nums[n-4]-nums[0], nums[n-3]-nums[1]);
        int option2 = min(nums[n-2]-nums[2], nums[n-1]-nums[3]);
        return min(option1, option2);

    }
};
