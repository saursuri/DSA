/*
Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        string temp;

        int i=0;
        while(i < s.length())
        {
            if (temp.size() > 0 && s[i] == ')' && temp.back() == '(')
            {
                temp.pop_back();
            }
            else
            {
                temp.push_back(s[i]);
            }

            i++;
        }

        return temp.size();
    }
};
