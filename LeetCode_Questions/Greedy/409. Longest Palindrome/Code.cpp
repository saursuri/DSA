/*
Problem Link: https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04
Time Complexity: O(n)
Space Complexity: O(56)
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int hash[52] = {0};

        for(auto ch: s)
        {
            if ('a'<=ch && ch<='z') hash[ch - 'a']++;
            if ('A'<=ch && ch<='Z') hash[26 + ch - 'A']++;
        }

        int ans=0;
        for(int i=0; i<52; i++)
        {
            ans += (hash[i]/2) * 2;
        }

        return (ans == s.length()) ? ans : ans+1;
    }
};
