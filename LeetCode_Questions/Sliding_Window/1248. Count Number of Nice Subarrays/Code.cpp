/*
Problem Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
Time ComplexitY: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int helper(vector<int>& nums, int goal)
    {
        if (goal<0) return 0;
        int left=0, right=0, count=0;
        int oddElems = 0;
        while(right<nums.size())
        {
            if (nums[right] % 2 == 1)
                oddElems++;

            while(oddElems>goal)
            {
                if (nums[left] % 2 == 1)
                    oddElems--;
                    
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        
        return helper(nums,goal) - helper(nums,goal-1);
    }
};
