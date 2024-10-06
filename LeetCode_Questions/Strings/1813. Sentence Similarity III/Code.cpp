/*
Problem Link: https://leetcode.com/problems/sentence-similarity-iii/?envType=daily-question&envId=2024-10-06
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <string>

class Solution {
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        auto splitSentence = [](const std::string &sentence) {
            std::vector<std::string> words;
            std::string word;
            for (char ch : sentence) {
                if (ch == ' ') {
                    if (!word.empty()) {
                        words.push_back(word);
                        word.clear();
                    }
                } else {
                    word += ch;
                }
            }
            if (!word.empty()) {
                words.push_back(word);  // Push the last word if it exists
            }
            return words;
        };
        
        std::vector<std::string> words1 = splitSentence(sentence1);
        std::vector<std::string> words2 = splitSentence(sentence2);

        // Ensure words1 is the longer one
        if (words1.size() < words2.size()) {
            std::swap(words1, words2);
        }

        int start = 0, end = 0;
        int m = words1.size(), n = words2.size();

        // Count matching words from the start
        while (start < n && words1[start] == words2[start]) {
            start++;
        }

        // Count matching words from the end
        while (end < n && words1[m - 1 - end] == words2[n - 1 - end]) {
            end++;
        }

        // Check if the number of matching words is enough
        return start + end >= n;  // Ensure all words in the shorter sentence are matched
    }
};
