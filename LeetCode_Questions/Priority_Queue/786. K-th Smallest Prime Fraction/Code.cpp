/*
Problem Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
Time Complexity: O(n^2logn)
Space Complexity: O(n^2)
*/
class Solution {
public:
    typedef pair<double,pair<int,int>> elements;    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<elements> pq;
        
        int n = arr.size();

        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                double frac = (double)arr[i]/(double)arr[j];

                if (pq.size()>=k)
                {
                    if (frac<pq.top().first)
                    {
                        pq.pop();
                        pq.push({frac,{arr[i],arr[j]}});
                    }
                }
                else
                {
                    pq.push({frac,{arr[i],arr[j]}});
                }
            }
            
        }

        return {pq.top().second.first, pq.top().second.second};
    }
};
