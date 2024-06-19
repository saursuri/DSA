/*
Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n*m)
Space Complexity: O(1)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;


        int checkpoint = 0;
        while (i < n)
        {

            if (haystack[i] == needle[j])
            {
                if (j == m -1) return i - m + 1;
                j++;
                i++;
            }
            else
            {
                i = checkpoint + 1;
                j=0;
                checkpoint = i;
            }

        }

        return -1;

    }
};
