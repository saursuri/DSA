/*
Problem Link: https://leetcode.com/problems/find-champion-ii/?envType=daily-question&envId=2024-11-26
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0);

        for(auto &it: edges)
        {
            indegree[it[1]]++;
        }

        int count=0, ans=0;
        for(int i=0; i<n; i++)
        {
            if (indegree[i] == 0) 
            {
                count++;
                ans = i;
            }

            if (count > 1) return -1;

        }

        return ans; 
    }
};
