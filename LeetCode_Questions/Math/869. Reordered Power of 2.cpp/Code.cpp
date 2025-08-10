/*
Problem Link: https://leetcode.com/problems/reordered-power-of-2/description/?envType=daily-question&envId=2025-08-10
Idea: 2^n grows exponentially, no of digits in any 2^n are always different
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto countDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i) == target) return true;
        }
        return false;
    }
};
