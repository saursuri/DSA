/*
Problem Link: https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

class Solution {
private:
    void generateParantheses(int index, int open, int close, int n, vector<string> &ans, string &validParantheses)
    {
        // If index reaches 2*n that means all the parantheses have been put then store ans and return
        if (index==2*n)
        {
            ans.push_back(validParantheses);
            return;
        }

        // Can put a opening parantheses when opening count is less than n
        if (open<n)
        {
            // Add open parantheses
            validParantheses.push_back('(');
            // Increase index and opening count
            generateParantheses(index+1,open+1,close,n,ans,validParantheses);
            validParantheses.pop_back();
        }

        // Can put a closing parantheses when closing count is less than opening count
        if (close<open)
        {
            // Add closing parantheses
            validParantheses.push_back(')');
            // Increase index and increase closing count
            generateParantheses(index+1,open,close+1,n,ans,validParantheses);
            validParantheses.pop_back();
        }

    }

public:
    vector<string> generateParenthesis(int n) {
        
        // Vector to store ans
        vector<string> ans;

        // String to store one parantheses formation
        string validParantheses;

        // Total parantheses will be 2*n --> n for opening and n for closing
        // Initially open and closing parantheses count is 0
        generateParantheses(0, 0, 0, n, ans, validParantheses);

        return ans;
    }
};
