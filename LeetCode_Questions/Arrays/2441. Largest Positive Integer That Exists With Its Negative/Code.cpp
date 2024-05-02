/*
Problem Link: 
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int low = 0, high = n-1;

        while(low<=high)
        {
            if(nums[low]+nums[high]==0) return nums[high];

            else if (abs(nums[low])>nums[high]) low++;
            else high--;
        }

        return -1;
        
    }
};
