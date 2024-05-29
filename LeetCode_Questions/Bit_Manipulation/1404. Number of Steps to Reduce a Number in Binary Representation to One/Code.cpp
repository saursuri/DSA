/*
Problem Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int ans = n - 1, carry = 0;

        for (int i = n - 1; i > 0; i--) {
            if (s[i] - '0' + carry == 1) {
                ans++;
                carry = 1;
            }
        }

        return ans + carry;
    }
};
