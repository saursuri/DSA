/*
Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: (1)
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;
        bool flag = true;
        while (i < n)
        {
            s[j] = s[i];

            if (s[i] == ' ' && flag == false)
            {
                flag = true;
                j++;
            }

            if (s[i] != ' ') 
            {
                flag = false;
                j++;
            }

            i++;
        }

        while (j < s.length() || s[s.length()-1] == ' ') 
            s.pop_back();
        
        i = 0, j = 0;
        n = s.length();
        reverse(s.begin(), s.end());

        while(i < n)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + j, s.begin() + i);
                j = i+1;
            }
            
            i++;
        }

        reverse(s.begin() + j, s.end());

        return s;
    }
};
