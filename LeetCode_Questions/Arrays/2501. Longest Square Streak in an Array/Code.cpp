/*
Problem Link: https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isPerfectSquare(int n) {
        int root = int(sqrt(n));
        return root * root == n;
    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b){return a>b;});
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 1;
        for(auto &it: nums)
        {
            if (st.find(it) == st.end()) continue;

            int n = it;
            int temp = 0;
            while(true)
            {
                if (st.find(n) != st.end())
                {
                    temp++;
                    st.erase(n);

                    if (isPerfectSquare(n))
                    {
                        n = int(sqrt(n));
                    }
                    
                }
                else break;
            }

            ans = max(ans, temp);
        }

        return (ans == 1) ? -1 : ans;

    }
};
