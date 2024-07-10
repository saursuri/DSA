/*
Problem Link: https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int ans = 0;
        for (auto &operation : logs)
        {
            if (ans < 0) ans=0;
            
            if (operation == "../")
                ans--;
            else if (operation == "./")
                continue;
            else
                ans++;
        }

        return ans<0 ? 0:ans;
    }
};
