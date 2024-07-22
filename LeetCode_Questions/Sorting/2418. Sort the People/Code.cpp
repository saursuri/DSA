/*
Problem Link: https://leetcode.com/problems/sort-the-people/?envType=daily-question&envId=2024-07-22
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> mp;
        int n = names.size();

        for (int i=0; i<n; i++)
        {
            mp.push_back({names[i], heights[i]});
        }

        auto fn = [&](pair<string, int> &a, pair<string, int> &b){
            return a.second > b.second;
        };

        sort(mp.begin(), mp.end(), fn);

        for(int i=0; i<n; i++)
            names[i] = mp[i].first;

        return names;
    }
};
