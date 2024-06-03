/*
Problem Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.length();
        int indx = 0;
        for (auto ch: s)
        {
            if (indx == n) break;

            if (ch == t[indx]) indx++;
        }

        return n - indx;
        
    }
};
