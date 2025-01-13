/*
Problem Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumLength(string s) {
        int hash[26] = {0};

        for (auto &it: s)
        {
            hash[it-'a']++;
        }

        int ans = 0;
        for(int i=0; i<26; i++)
        {

            if (hash[i] > 2)
            {
                ans += (hash[i]%2==0)?2:1;
            }
            else ans += hash[i];
        }

        return ans;
    }
};
