/*
Problem Link: https://leetcode.com/problems/find-center-of-star-graph/description/
Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else return edges[0][1];

    }
};
