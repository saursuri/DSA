/*
Problem Link: https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
Approach: Using Two Pointers
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();

        int high = -1;
        for (int index = 0; index < n; index++) {
            if (ch == word[index]) {
                high = index;
                break;
            }
        }

        if (high == -1)
            return word;

        int low = 0;
        while (low <= high) {
            swap(word[low], word[high]);
            low++;
            high--;
        }
        return word;
    }
};
