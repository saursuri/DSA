/*
Problem Link: https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        for (int i=s.length()-1; i>=0; i--)
        {
            if (s[i] == ' ' && len == 0) continue;
            else if (s[i] == ' ' && len > 0) break;

            len++;
        }

        return len;
    }
};
