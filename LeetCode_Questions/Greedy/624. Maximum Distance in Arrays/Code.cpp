/*
Problem Link: https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int m;
        int maxm = INT_MIN, smaxm = INT_MIN,
        minm = INT_MAX, sminm = INT_MAX;

        int max_indx = -1, min_indx = -1;
        for(int i=0; i<n; i++)
        {
            if (arrays[i][0] < minm)
            {
                sminm = minm;
                minm = arrays[i][0];
                min_indx = i;
            }
            else if (arrays[i][0] < sminm)
            {
                sminm = arrays[i][0];
            }

            m = arrays[i].size();
            if (arrays[i][m-1] > maxm)
            {
                smaxm = maxm;
                maxm = arrays[i][m-1];
                max_indx = i;
            }
            else if (arrays[i][m-1] > smaxm)
            {
                smaxm = arrays[i][m-1];
            }
            
        }

        if (max_indx == min_indx)
        {
            return max(maxm-sminm, smaxm-minm);
        }
        else
        {
            return maxm-minm;
        }
    }
};
