/*
Problem Link: https://leetcode.com/problems/number-of-wonderful-substrings/description/
Time Complexity: O(n)
Space Complexity: O(n) --> Unordered Map
*/

class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {

        unordered_map<ll, ll> mp;
        mp[0] = 1;
        ll cumm_xor = 0;
        ll result = 0;

        for (auto ch : word) {
            ll shift = ch - 'a';
            // 1<<shift --> Binary representation of the character
            cumm_xor ^= (1 << shift);

            // If cumm_xor already exist in mp increase the count
            // All characters are even in count
            result += mp[cumm_xor];

            // xor each character with the cumm_xor to check for
            // odd number of characters in sub string
            for (char ch1 = 'a'; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';
                ll check_xor = cumm_xor ^ (1 << shift);

                // if check_xor already exist in mp increase the count
                result += mp[check_xor];
            }

            mp[cumm_xor]++;
        }

        return result;
    }
};
