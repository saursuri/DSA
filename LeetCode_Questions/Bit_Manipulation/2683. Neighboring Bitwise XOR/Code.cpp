/*
Problem Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;

        for(auto &it: derived)
            XOR ^= it;
        
        return XOR==0;
    }
};
