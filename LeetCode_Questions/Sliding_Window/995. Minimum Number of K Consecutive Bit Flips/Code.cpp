/*
Problem Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        int totalFlips = 0;
        vector<bool> isFlipped(n, false);

        for (int i=0; i<n; i++)
        {
            // If Flips is increased by i-k element then decrease the flips
            // Window sliding here
            if (i >= k && isFlipped[i-k] == true)
                flips--;

            if (nums[i] == flips % 2) 
            {
                
                if (i + k > n)
                    return -1;

                totalFlips++;
                flips++;
                isFlipped[i] = true;
            }
            
        }

        return totalFlips;
    }
};
