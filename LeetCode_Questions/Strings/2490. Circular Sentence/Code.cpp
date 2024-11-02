/*
Problem Link: https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();

        char toMatch = sentence[n-1];
        if (sentence[0] != toMatch) return false;

        for(int i=1; i<n-1; i++)
        {
            if (sentence[i+1] == ' ')
            {
                toMatch = sentence[i];
            }

            if (i+1 < n && sentence[i] == ' ' && sentence[i+1] != toMatch) return false;
        }

        return true;
    }
};
