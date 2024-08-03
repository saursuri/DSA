/*
Problem Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());

        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i] != target[i]) return false;
        }

        return true;

    }
};
