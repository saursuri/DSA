/*
Problem Link: https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>> pq;

        for(int i=0; i<n; i++)
        {
            pq.push({score[i],i});
        }

        vector<string> ranks(n);
        int pos = 1;
        while(!pq.empty())
        {
            auto pqTop = pq.top();
            pq.pop();

            if (pos==1)
                ranks[pqTop.second] = "Gold Medal";
            else if (pos==2)
                ranks[pqTop.second] = "Silver Medal";
            else if (pos==3)
                ranks[pqTop.second] = "Bronze Medal";
            else
                ranks[pqTop.second] = to_string(pos);
            pos++;

        }

        return ranks;
    }
};
