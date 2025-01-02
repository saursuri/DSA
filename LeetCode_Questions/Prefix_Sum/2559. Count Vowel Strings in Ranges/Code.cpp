/*
Problem Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    bool isValid(string &word)
    {
        int first = word[0];
        int second = word[word.size()-1];
        int matched = 0;
        string vowels = "aeiou";
        for (auto &it: vowels)
        {
            if (first == it) matched++;
            if (second == it) matched++;
        }
        
        return matched==2;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n,0);

        for(int i=0; i<n; i++)
        {
            int toAdd = isValid(words[i]) ? 1 : 0;
            prefixSum[i] = toAdd + (i==0 ? 0 : prefixSum[i-1]); 

        }

        vector<int> ans;
        for (auto &it: queries)
        {
            int a = it[0], b = it[1];
            
            int first = prefixSum[a];
            int second = prefixSum[b];

            if (isValid(words[a]))
            {
                ans.push_back(second-first+1);
            }
            else            
                ans.push_back(second-first);
        }

        return ans;
    }
};
