/*
Problem Link: https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10
Time Complexity: O(m+n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int toMatchHash[26] = {0}; 

        // Build the toMatchHash for words2
        for (const string& word : words2) {
            int tempHash[26] = {0};
            for (char ch : word) {
                tempHash[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                toMatchHash[i] = max(toMatchHash[i], tempHash[i]);
            }
        }

        vector<string> ans;

        // Check each word in words1
        for (const string& word : words1) {
            int hash[26] = {0};
            for (char ch : word) {
                hash[ch - 'a']++;
            }

            // Verify if the current word satisfies toMatchHash
            bool isValid = true;
            for (int i = 0; i < 26; i++) {
                if (hash[i] < toMatchHash[i]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                ans.push_back(word);
            }
        }

        return ans;
    }

};
