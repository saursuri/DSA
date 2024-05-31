/*
Problem Link: https://leetcode.com/problems/single-number-iii/?envType=daily-question&envId=2024-05-31
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor = 0;

        for (auto num: nums)
        {
            overall_xor ^= num;
        }

        int bit = 0;
        while (((overall_xor >> bit) & 1) != 1)
            bit += 1;
        
        int firstNo = 0;
        int secondNo = 0;

        for (auto num: nums)
        {
            if (num & (1<<bit))
            {
                firstNo ^= num;
            }
            else
            {
                secondNo ^= num;
            }
        }

        return {firstNo, secondNo};
    }
};
