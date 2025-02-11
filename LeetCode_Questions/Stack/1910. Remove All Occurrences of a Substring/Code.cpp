/*
Problem Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11
Time Complexity: O(m*n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack;  // Acts as a stack to build the final string
        int m = part.size();
        
        for (char c : s) {
            stack.push_back(c);
            
            // Check if the last m characters match `part`
            if (stack.size() >= m && stack.substr(stack.size() - m) == part) {
                stack.erase(stack.end() - m, stack.end()); // Remove `part`
            }
        }
        return stack;
    }
};
