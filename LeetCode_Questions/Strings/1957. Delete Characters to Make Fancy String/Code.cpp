/*
Problem Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char prevChar = '0';
        int count = 0;
        for (auto &it : s)
        {
            if (prevChar == it)
            {
                count++;
                if (count >= 2)
                {
                    continue;
                }
            }
            else count = 0;
            prevChar = it;
            ans += it;
        }

        return ans;
    }
};
