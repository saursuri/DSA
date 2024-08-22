/*
Problem Link: https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
Time Complexity: O(32)
Space Complexity: O(1)
*/

class Solution {
public:
    int findComplement(int num) {
        int copy = num;
        int mask = 0;
        while(copy)
        {
            mask = (mask<<1)|1;
            copy = copy>>1;
        }

        return mask^num;
    }
};
