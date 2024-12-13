/*
Problem Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    typedef pair<int,int> iPair;
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        for(int i=0; i<n; i++)
        {
            pq.push({nums[i], i});
        }

        vector<bool> marked(n, false);

        long long score = 0;
        while(!pq.empty())
        {
            auto pqTop = pq.top();
            int num = pqTop.first;
            int index =  pqTop.second;
            
            if (marked[index] == false)
            {
                score += num;
                marked[index] = true;
                if (index > 0) marked[index-1] = true;
                if (index < n-1) marked[index+1] = true;
            }

            while(marked[index] == true && !pq.empty())
            {
                pq.pop();
                pqTop = pq.top();
                num = pqTop.first;
                index = pqTop.second;
            }

        }

        return score;
    }
};
