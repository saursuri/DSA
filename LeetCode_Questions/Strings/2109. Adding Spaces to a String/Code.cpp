/*
Problem Link: https://leetcode.com/problems/adding-spaces-to-a-string/?envType=daily-question&envId=2024-12-03
Time Complexity: O(N) where N is the size of string s
Space Complexity: O(1)
*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int csptr = spaces[0];
        string ans;

        int n = s.length();
        int i = 0, j=0;
        while(i<n)
        {
            if (i == csptr)
            {
                if (j<spaces.size()-1) j++;
                
                csptr = spaces[j];
                ans.append(" ");
                
            }

            ans += s[i];
            i++;
        }

        return ans;
    }
};
