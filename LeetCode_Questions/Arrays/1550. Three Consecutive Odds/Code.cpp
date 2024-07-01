/*
Problem Link: https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2024-07-01
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (auto num : arr)
        {
            if (1 == num % 2) count++;
            else count = 0;

            if (count == 3) return true;
        }

        return false;
    }
};
