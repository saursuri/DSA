/*
Problem Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k) return false;

        int hash[26] = {0};

        for(int i=0; i<n; i++)
        {
            hash[s[i]-'a']++;
        }

        int odds=0;
        for(int i=0; i<26; i++)
        {
            if (hash[i]%2==1) odds++;
        }

        return odds<=k;
    }
};
