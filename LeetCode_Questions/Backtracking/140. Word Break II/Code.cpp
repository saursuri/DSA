/*
Problem Link: https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25
Time Complexity: O(2^n)
Space Complexity: O(n) --> Recursion Stack + O(2^n) --> No of substrings
*/

class Solution {
    void wordBreakUtil(int index, string& s, vector<string>& ans,
                       string& currString, unordered_set<string>& hash) {
        int n = s.size();
        if (index == n) {
            ans.push_back(currString);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            string tempString = s.substr(index, i - index + 1);
            if (hash.count(tempString)) {
                string temp = currString;
                if (!currString.empty()) {
                    currString += " ";
                }
                currString += tempString;
                wordBreakUtil(i + 1, s, ans, currString, hash);
                currString = temp;
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string currString;
        unordered_set<string> hash;
        for (auto word : wordDict)
            hash.insert(word);

        wordBreakUtil(0, s, ans, currString, hash);
        return ans;
    }
};
