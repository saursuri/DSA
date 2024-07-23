/*
Problem Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        for(auto &it: nums)
        {
            mp[it]++;
        }

        auto fn = [&](int &a, int &b){
            if (mp[a] == mp[b])
                return a > b;
            
            return mp[a] < mp[b];
        };

        sort(nums.begin(), nums.end(), fn);

        return nums;
    }
};
