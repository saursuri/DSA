/*
Problem Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2025-01-25
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int group = 0;
        unordered_map<int, vector<int>> groupMap;
        unordered_map<int, int> groupNum;

        // Create groups based on the limit
        groupMap[group].push_back(sortedNums[0]);
        groupNum[sortedNums[0]] = group;

        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i - 1] > limit) {
                group++;
            }
            groupMap[group].push_back(sortedNums[i]);
            groupNum[sortedNums[i]] = group;
        }

        // Reconstruct the lexicographically smallest array
        vector<int> ans;
        unordered_map<int, int> groupIndex; // Track position in each group

        for (int i = 0; i < n; i++) {
            int gNum = groupNum[nums[i]];
            if (groupIndex.find(gNum) == groupIndex.end()) {
                groupIndex[gNum] = 0;
            }
            ans.push_back(groupMap[gNum][groupIndex[gNum]]);
            groupIndex[gNum]++;
        }

        return ans;
    }
};
