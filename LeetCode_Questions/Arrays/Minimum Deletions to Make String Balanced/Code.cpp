/*
Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30
Time Complexity: O(2*n)
Space ComplexitY: O(1)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int counta = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        int countb = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                counta--;
                
            count = min(count, countb + counta);

            if(s[i] == 'b')
                countb++;
        }

        return count;
    }
};
