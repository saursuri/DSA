/*
Problem Link: https://leetcode.com/problems/string-compression-iii/?envType=daily-question&envId=2024-11-04
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string compressedString(string word) {
        int currCharCount = 0;
        char currChar, nextChar;
        int n = word.length();
        string ans;

        for (int i=0; i<n; i++)
        {
            currChar = word[i];
            nextChar = (i+1 < n) ? word[i+1] : ' ';
            currCharCount++;

            // If CharChange
            if (currChar != nextChar)
            {
                ans += to_string(currCharCount);
                ans += currChar;
                currCharCount = 0;
            }
            else
            {
                if (currCharCount > 8)
                {
                    ans += to_string(currCharCount);
                    ans += currChar;
                    currCharCount = 0;
                }
            }
        }

        return ans; 
    }
};
