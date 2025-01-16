/*
Problem Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16
Time Complexity: O(m+n)
Space Complexity: O(1)
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans=0;
        if (m%2==0 && n%2==0) return 0;
        else if (m%2==1 && n%2==0)
        {
            for(auto &it: nums2)
                ans ^= it;
        }
        else if (m%2==0 && n%2==1)
        {
            for(auto &it: nums1)
                ans ^= it;
        }
        else
        {
            for(auto &it: nums1)
                ans ^= it;
            
            for(auto &it: nums2)
                ans ^= it;
        }

        return ans;
    }
};
