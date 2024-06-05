/*
Problem Link: https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
Time Complexity: O(n*k) --> n represents no of words and k represents length of chars in words
Space Complexity: O(n) 
*/
class Solution {
public:
    int hash[100][26];
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();

        for(int i=0; i<n; i++)
        {
            for (auto ch: words[i])
                hash[i][ch-'a']++;
        }
        
        vector<string> ans;

        for (int i=0; i<26; i++)
        {
            int minval = INT_MAX;
            for(int j=0; j<n; j++)
                minval = min(minval, hash[j][i]);

            for(int k=0; k<minval; k++)
                ans.push_back(string(1,char(i + 'a')));

        }

        return ans;

    }
};
