/*
Problem Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23
Time Complexity: O(nlogn)
Space Complexity: O(nlogn)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int> st;

        int left = 0, right = 0;

        int window = 0;
        while (right < n)
        {
            st.insert(nums[right]);
            if (*st.rbegin() - *st.begin() > limit)
            {
                st.erase(st.find(nums[left]));
                left++;
            }

            window = max(window, right-left + 1);
            
            right++;
        }

        return window;
    }
};
