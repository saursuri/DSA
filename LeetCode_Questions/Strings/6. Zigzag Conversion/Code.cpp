/*
Problem Link: https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n + m)
Space Complexity: O(m)

*/
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();

        if (numRows == 1) return s;
        
        vector<string> rows(numRows);
        string ans;

        int indx = 0, dir = 1;
        int j = 0;
        while (indx < n)
        {
            if (j == 0)
                dir = 1;
            if (j == numRows - 1)
                dir = -1;

            rows[j] += s[indx];
            j += dir; 
            indx++;
        }

        for (auto row: rows)
            ans += row;
        
        return ans;
    }
};
