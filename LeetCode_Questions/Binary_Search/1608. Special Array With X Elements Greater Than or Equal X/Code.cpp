/*
Problem Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
Time Complexity: O(nlogn + logn*logn) --> Sorting + BS*BS
Space Complexity: O(1)
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low=0, high=n;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int indx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            if (n - indx == mid) return mid;
            else if (n - indx > mid) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};
