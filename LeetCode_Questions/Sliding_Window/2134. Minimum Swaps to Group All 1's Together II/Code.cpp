/*
Problem Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02
Time Complexity: O(n)
Space ComplexitY: O(1)
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total = 0;

        for (auto &it : nums)
        {
            if (it == 1) total++;
        }

        int n = nums.size();
        int swapsRequired = 0;
        for (int i=0; i<total; i++)
        {
            if (nums[i]==0) swapsRequired++;
        }
        int minSwaps = swapsRequired;
        for (int i=total; i<2*n; i++)
        {   
            int j = i >= total + n ? i%n : i;
            swapsRequired = swapsRequired - !nums[j-total] + !nums[i%n];
            minSwaps = min(minSwaps, swapsRequired);
        }

        return minSwaps;

    }
};
