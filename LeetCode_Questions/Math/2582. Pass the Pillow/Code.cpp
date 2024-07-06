/*
Problem Link: https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int passThePillow(int n, int time) {

        int pillow = 1;
        int dir = 1;
        while (time)
        {
            if (pillow == 1)
                dir = 1;
            if (pillow == n)
                dir = -1;
            
            pillow += dir;
            time--;
        }

        return pillow;
    }
};
