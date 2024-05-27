/*
Problem Link: https://www.geeksforgeeks.org/problems/shortest-job-first/1
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        int n = bt.size();
        
        int waitTime[n];
        for(int index=0; index<n; index++)
        {
            waitTime[index] = (index-1<0)?0:(waitTime[index-1] + bt[index-1]); 
        }
        
        int totalWaitTime = 0;
        for(int i=0; i<n; i++)
        {
            totalWaitTime += waitTime[i];
        }
        
        return totalWaitTime/n;
    }
};
