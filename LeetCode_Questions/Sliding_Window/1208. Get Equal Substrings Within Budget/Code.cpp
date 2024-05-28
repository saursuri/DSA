/*
Problem Link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length();
        int left = 0, right = 0;
        int currentCost=0, maxLen=0;
        while (right < n)
        {
            currentCost += abs(s[right]-t[right]);

            // Try to shrink the window
            if (currentCost > maxCost && left < n)
            {
                currentCost -= abs(s[left]-t[left]);
                left = left + 1;
            }

            maxLen = max(maxLen, right-left+1);

            right = right + 1;
        }

        return maxLen;
    }
};
