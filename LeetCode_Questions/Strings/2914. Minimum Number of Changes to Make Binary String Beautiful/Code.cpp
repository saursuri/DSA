/*
Problem Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        
        for (int i=0; i<s.length() - 1; i+=2)
        {
            char firstNo = s[i];
            char secondNo = s[i+1];

            if (firstNo != secondNo)
            {
                count++;
            }
        }

        return count;
    }
};
