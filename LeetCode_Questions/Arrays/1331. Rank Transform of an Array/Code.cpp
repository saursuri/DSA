/*
Problem Link: https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class custom{
    public: 
        int val;
        int indx;
        int rank;
};

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<custom> ds;
        
        int i=0;
        for (auto &it: arr)
        {
            ds.push_back({it,i++,0});
        }

        sort(ds.begin(), ds.end(), [&](custom a1, custom a2){return a1.val < a2.val;});
        
        i=1;
        for(int x=0; x<ds.size(); x++)
        {
            if (x>0 && ds[x].val != ds[x-1].val)
            {
                i++;
            }

            ds[x].rank = i;
        }

        sort(ds.begin(), ds.end(), [&](custom a1, custom a2){return a1.indx < a2.indx;});

        vector<int> ans;

        for (auto &it: ds)
        {
            ans.push_back(it.rank);
        }

        return ans;
    } 
};
