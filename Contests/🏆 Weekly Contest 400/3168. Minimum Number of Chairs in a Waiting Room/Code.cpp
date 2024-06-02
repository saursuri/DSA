/*
Problem Link: https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int minimumChairs(string s) {
        
        int chairs = 0;
        int minChairs = 0;
        for(auto ch: s)
        {
            if (ch == 'E') chairs++;
            else chairs--;

            minChairs = max(minChairs, chairs);
        }
        
        return minChairs;
    }
};
