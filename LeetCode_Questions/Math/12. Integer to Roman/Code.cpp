/*
Problem Link: https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result;

        for(auto &p : roman)
        {
            while(num >= p.first)
            {
                result += p.second;
                num -= p.first;
            }
        }

        return result;
    }
};
