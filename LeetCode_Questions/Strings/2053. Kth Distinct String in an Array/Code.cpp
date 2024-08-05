/*
Problem Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for (auto &it : arr)
        {
            mp[it]++;
        }

        int indx = 0;
        for(auto &it: arr)
        {
            if (mp[it] == 1) indx++;
            if (indx == k) return it;
        }
        return "";
    }
};
