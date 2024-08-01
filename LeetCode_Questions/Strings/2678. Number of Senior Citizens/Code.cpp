/*
Problem Link: https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int count=0;
        int n = details.size();
        for (int i=0; i<n; i++)
        {
            if (details[i][11]=='6' && details[i][12]=='0') continue;
            if (details[i][11]>='6' && details[i][12]>='0') count++;
        }

        return count;
    }
};
