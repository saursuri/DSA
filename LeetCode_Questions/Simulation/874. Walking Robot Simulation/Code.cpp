/*
Problem Link: https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-04
Time Complexity: O(nlogn + m*k*logn) where n is the no of obstacles, m is the no. of commands
Space Conplexity: O(n)
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;

        set<vector<int>> st(obstacles.begin(), obstacles.end());

        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        int i=0;
        int r=0, c=0;
        for (auto &it: commands)
        {
            if (it == -2) // Left
            {
                i = (4 + i - 1) % 4;
            }
            else if (it == -1) // Right
            {
                i = (4 + i + 1) % 4;
            }
            else
            {
                while(it--)
                {
                    int nR = r + dr[i];
                    int nC = c + dc[i];
                    
                    if (st.count({nR,nC}))
                    {
                        break;
                    }

                    r = nR;
                    c = nC;

                    int dis = r*r + c*c;
                    ans = max(ans, dis); 
                }

            }
            
        }

        return ans;
    }
};
