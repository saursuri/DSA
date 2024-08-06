/*
Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06
Time Complexity: O(n)
Space Complexity: O(26)
*/

class Solution {
public:
    int minimumPushes(string word) {

        int mp[26];
        memset(mp, 0, sizeof(mp));

        for (auto &it : word)
        {
            mp[it - 'a']++;
        }

        sort(mp, mp + 26, greater<int>()); 

        int indx = 0, ans=0;
        for (int i=0; i<26; i++)
        {
            ans += (indx/8 + 1) * mp[i];
            indx++;
        }

        return ans;
    }
};
