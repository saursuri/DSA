/*
Problem Link: https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());

        int count = 0;
        int n = heights.size();
        for(int i=0; i<n; i++)
        {
            if (heights[i] != expected[i])  
                count++;
        }

        return count;
    }
};
