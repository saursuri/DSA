/*
Problem Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04
Time Complexity: O(m)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();

        int i=0, j=0;

        while(i<m && j<n)
        {
            char chr = (str1[i]-'a'==25)?'a':char(str1[i]+1);

            if (str2[j] == str1[i] || str2[j] == chr)
            {
                j++;
            }

            i++;
        }
        
        return j==n;
    }
};
