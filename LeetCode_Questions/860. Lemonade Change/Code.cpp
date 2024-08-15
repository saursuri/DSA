/*
Problem Link: https://leetcode.com/problems/lemonade-change/?envType=daily-question&envId=2024-08-15
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money[2]= {0};

        for(auto bill: bills)
        {
            if (bill == 5)
            {
                money[0]++;
            }
            else if (bill == 10)
            {
                if (money[0]>0) 
                {
                    money[1]++;
                    money[0]--;
                }
                else return false;
            }
            else
            {
                if (money[1]>0 && money[0]>0)
                {
                    money[1]--;
                    money[0]--;
                }
                else if (money[0]>=3)
                {
                    money[0] -= 3;
                }
                else return false;
            }
        }

        return true;
    }
};
