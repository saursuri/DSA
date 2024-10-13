/*
Problem Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
Time Complexity: O(nlogk)
Space Complexity: O(k)
*/

class pqElements{
    public:
        int minEl;
        int listIndx;
        int indx;
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> desiredRange = {static_cast<int>(-10e5), static_cast<int>(10e5)};

        auto func = [](pqElements &p1, pqElements &p2){
            return p1.minEl > p2.minEl;
        };

        // PQ to get the minimum element
        priority_queue<pqElements, vector<pqElements>, decltype(func)> pq(func);

        // Store the first element from each list
        int listIndx=0, maxEl = INT_MIN;
        for (auto &it: nums)
        {
            pq.push({it[0], listIndx++, 0});
            maxEl = max(maxEl, it[0]);
        }

        while(!pq.empty())
        {
            auto pqTop = pq.top();
            pq.pop();

            if (maxEl - pqTop.minEl < desiredRange[1] - desiredRange[0])
            {
                desiredRange[0] = pqTop.minEl;
                desiredRange[1] = maxEl;
            }

            // Check if the indx of any list doesn't go out of range
            if (pqTop.indx + 1 < nums[pqTop.listIndx].size())
            {
                int nextEl = nums[pqTop.listIndx][pqTop.indx+1];
                pq.push({nextEl, pqTop.listIndx, pqTop.indx+1});
                maxEl = max(maxEl, nextEl);
            }
            else break;
        }

        return desiredRange;
    }
};
