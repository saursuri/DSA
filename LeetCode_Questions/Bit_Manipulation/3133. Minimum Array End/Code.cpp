/*
Problem Link: https://leetcode.com/problems/minimum-array-end/description/?envType=daily-question&envId=2024-11-09
Time Complexity: O(1)
Space Complexity: O(1)
*/

typedef long long ll;
class Solution {
public:
    long long minEnd(int n, int x) {

        long long ans = 0;
        int i = 0, k=0;
        int j = 0;
        
        while (i < 64) {
            int nBits = ((k<32) && ((1 << k++) & (n - 1))) ? 1 : 0;

            // If the current bit of x is set, copy it to ans
            while ((x & (1LL << i)) != 0) {
                ans |= (1LL << i);
                i++;
            }
            
            // Otherwise, use the bits from nBits for the remaining bits
            ans |= (ll(nBits) << i);
            i++;
        }

        return ans;
    }
};
