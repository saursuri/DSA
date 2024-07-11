/*
Problem Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> q;

        for(int i=0;i<s.length();i++)
        {
            if(st.empty()) 
                st.push(s[i]);
            else if(s[i]==')')
            {
                // Pop until (
                while(st.top()!='(')
                {   
                    q.push(st.top());
                    st.pop();
                }
                // Pop (
                st.pop();
                // Push elements from q to stack
                while(!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
