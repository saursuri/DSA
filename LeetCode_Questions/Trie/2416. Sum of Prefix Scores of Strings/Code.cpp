/*
Problem Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

class trie_node{
    int count = 0;
    trie_node* list[26] = {nullptr};
    public:
        trie_node* next_char(char &ch)
        {
            return list[ch - 'a'];
        }

        void add_char(char &ch)
        {
            list[ch-'a'] = new trie_node;
        }

        void inc_count(char &ch)
        {
            list[ch-'a']->count += 1;
        }

        bool contains_char(char &ch)
        {
            if (list[ch-'a'] != nullptr)
                return true;
            else return false;
        }

        int ret_count(char &ch){
            return list[ch-'a']->count;
        }

};

class Solution {
    trie_node *root_node;

public:
    Solution(){
        root_node = new trie_node();
    }

    void insert(string &word){
        trie_node* trie_ptr = root_node;

        for (auto &ch: word)
        {
            if (!trie_ptr->contains_char(ch)) // If trie doesn't contain the character
            {
                trie_ptr->add_char(ch);
            }

            // Increase the character count
            trie_ptr->inc_count(ch);

            // Move to the next character
            trie_ptr = trie_ptr->next_char(ch);
        }
    }
    
    int search(string &word)
    {
        trie_node* trie_ptr = root_node;

        int counter = 0;
        for (auto &ch: word)
        {
            counter += trie_ptr->ret_count(ch);
            trie_ptr = trie_ptr->next_char(ch);
        }

        return counter;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;

        for (auto &word: words)
        {
            insert(word);
        }
        
        for (auto &word: words)
        {
            ans.push_back(search(word));
        }
        

        return ans;
    }
};
