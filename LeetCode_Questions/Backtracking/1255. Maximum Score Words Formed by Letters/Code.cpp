/*
Problem Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/?envType=daily-question&envId=2024-05-24
Time Complexity: 2^n*(m) --> m is the average length of word[i]
Space Complexity: O(n) --> Recursive Stack
*/
class Solution {
    bool canTake(string &word, vector<int> hash)
    {
        for (auto ch: word)
        {
            if (hash[ch-'a']==0) return false;
            hash[ch-'a']--;
        }

        return true;
    }
    
    void updateHash(string &word, vector<int> &hash)
    {
        for (auto ch: word)
        {
            hash[ch-'a']--;
        }
    }

    void backTrack(string &word, vector<int> &hash)
    {
        for (auto ch: word)
        {
            hash[ch-'a']++;
        }
    }

    int findScore(string &word, vector<int> &score)
    {
        int ans=0;
        for(auto ch: word)
        {
            ans += score[ch-'a'];
        }

        return ans;
    }

    int maxScoreWordsUtil(int index, vector<string>& words, vector<int> &hash, vector<int> &score)
    {
        int n = words.size();

        if (index == n) return 0;

        int notTake = maxScoreWordsUtil(index+1, words, hash, score);

        int take = 0;
        if (canTake(words[index], hash))
        {
            updateHash(words[index], hash);
            take = findScore(words[index], score) + maxScoreWordsUtil(index+1, words, hash, score);
            backTrack(words[index], hash);
        }
        return max(notTake, take);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> hash(26,0);
        for(auto ch: letters)
        {
            hash[ch-'a']++;
        }

        return maxScoreWordsUtil(0, words, hash, score);
    }
};
