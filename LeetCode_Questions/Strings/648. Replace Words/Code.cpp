/*
Problem Link: https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07

Time Complexity: O(n^2) in the worst case. sentence.substr(j,i-j) takes O(k) TC
and worst case it will be O(n) and main loop is another O(n) --> O(n^2) 

Space Complexity: O(n+l) --> where n is the length of the sentence and l is the total
length of all words in the dictionary
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        unordered_set<string> hash(dictionary.begin(), dictionary.end());

        int n = sentence.length();
        int j = 0, i = 0;

        string ans;
        while (i < n) {
            if (hash.count(sentence.substr(j, i - j))) {
                ans += sentence.substr(j, i - j);
                while (i < n && sentence[i] != ' ')
                    i++;
                j = i;
            }

            if (sentence[i] == ' ') {
                if (!hash.count(sentence.substr(j, i - j)))
                    ans += sentence.substr(j, i - j) + ' ';

                j = i + 1;
            }

            i++;
        }

        ans += sentence.substr(j, n - j);

        return ans;
    }
};
