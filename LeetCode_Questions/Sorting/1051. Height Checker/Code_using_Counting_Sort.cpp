/*
Problem Link: https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
Time Complexity: O(n + range)
Space Complexity: O(n + range)
*/
class Solution {
    void countingSort(vector<int>& heights)
    {
        int minHeight = *min_element(heights.begin(), heights.end());
        int maxHeight = *max_element(heights.begin(), heights.end());

        unordered_map<int, int> mp;

        for (auto height: heights) mp[height]++;

        int i=0;
        for(int height=minHeight; height <= maxHeight; height++)
        {
            while(mp[height] > 0)
            {
                heights[i] = height;
                i++;
                mp[height]--;
            }
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights(heights.begin(), heights.end());

        countingSort(heights);
        int n = heights.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if (heights[i] != sortedHeights[i]) count++;
        }
    

        return count;
    }
};
