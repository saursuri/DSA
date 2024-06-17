/*
Problem Link: https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());

        int maxCitation = 0;
        int n = citations.size();

        for (int i=0; i<n; i++)
        {
            maxCitation = max(maxCitation, min(citations[i] , n - i));
        }

        return maxCitation;
    }
};
