/*
Problem Link: https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n * m) --> m is the average length of the words
Space Complexity: O (1) 
*/

class Solution {
    int compare(string &s1, string &s2, int len)
    {
        int m = s1.length();
        int n = s2.length();

        int i=0;
        int l = 0;
        while (i<min(len,min(m,n)))
        {
            if (s1[i] == s2[i]) l++;
            else break;
            i++;
        }

        return l;

    }

public:
    string longestCommonPrefix(vector<string>& strs) {
       
       if (strs.size() == 1) return strs[0]; 

       int n = strs.size();

        int len = INT_MAX;
       for (int i=1; i<n; i++)
       {
            len = min(len, compare(strs[i-1], strs[i], len));
       }

       return strs[0].substr(0,len);
    }
};
