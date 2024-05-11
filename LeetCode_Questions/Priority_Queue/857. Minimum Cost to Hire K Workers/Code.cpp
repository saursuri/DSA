/*
Problem Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/?envType=daily-question&envId=2024-05-11
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        vector<pair<double, int>> worker_ratio(n);

        // Find the worker ratio --> wage[worker]/quality[worker]
        // TC: O(n)
        for (int worker=0; worker<n; worker++)
        {
            worker_ratio[worker] = {(double)wage[worker]/(double)quality[worker], quality[worker]};
        }

        // TC: O(nlogn)
        // Sort the worker ratio increasingly
        sort(worker_ratio.begin(), worker_ratio.end());

        // Creating max PQ, so the greatest quality will be on top
        priority_queue<int> pq;

        // Find sum of quality of k workers
        // TC: O(klogk)
        int sum_quality = 0;
        for(int worker=0; worker<k; worker++)
        {
            pq.push(worker_ratio[worker].second);
            sum_quality += worker_ratio[worker].second;
        }

        // Find the manager ratio
        double manager_ratio = worker_ratio[k-1].first;
        // Result considering the current manager
        double result = manager_ratio * sum_quality;

        // Need to find the minimum result so iterate
        // from k to n
        // TC: O(nlogn)
        for (int i=k; i<n; i++)
        {
            // Find manager_ratio same as above
            manager_ratio = worker_ratio[i].first;
            
            // Push to PQ
            pq.push(worker_ratio[i].second);
            // Find the sum_quality
            sum_quality += worker_ratio[i].second;

            // If the pq.size() increases from k
            // decrease the pq.size() by popping the 
            // worker with max quality from pq.top()
            if (pq.size()>k)
            {
                sum_quality -= pq.top();
                pq.pop();
            }

            // Need to maintain the min group of workers so wages 
            // can be minimized
            result = min(result, manager_ratio*sum_quality);
        }

        return result;

    }
};
