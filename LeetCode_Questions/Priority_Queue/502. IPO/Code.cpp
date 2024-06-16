/*
Problem Link: https://leetcode.com/problems/patching-array/description/?envType=daily-question&envId=2024-06-16
Time Complexity: O(n) + O(nlogn) + O(nlogn) --> vector insertion O(n) + vector sorting O(nlogn) + PQ Insertion O(nlogn)
Space Complexity: O(n) --> Vector for profits, capital and pq in max case can take n profits
*/
class compare{
    public:
        int cap;
        int prof;
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<compare> v;
        int n = profits.size();

        for(int i=0; i<n; i++)
        {
            v.push_back({capital[i], profits[i]});
        }

        auto sortcompare = [&](const compare &a, const compare &b)
        {
            return a.cap < b.cap;
        };

        sort(v.begin(), v.end(), sortcompare);

        
        priority_queue<int> pq;

        int indx = 0;
        
        while(k--)
        {   
            
            while(indx < n && v[indx].cap <= w)
            {
                pq.push(v[indx].prof);
                indx++;
            }
            
            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
