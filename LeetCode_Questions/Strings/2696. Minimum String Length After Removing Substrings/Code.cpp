/*
Problem Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-07
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        string temp;
        int i=0;

        while (i < n) {
            if (!temp.empty() && ((temp.back() == 'A' && s[i] == 'B') || (temp.back() == 'C' && s[i] == 'D')))
            {
                temp.pop_back();
            }
            else
            {
                temp.push_back(s[i]);
            }

            i++;
        }

        return temp.length();
    }
};
