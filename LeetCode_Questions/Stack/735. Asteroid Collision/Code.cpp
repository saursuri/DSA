/*
Problem Link: https://leetcode.com/problems/asteroid-collision/description/
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        int n = ast.size();
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            // ast[i] is +ve here
            if (st.empty() || ast[i] > 0)
            {
                st.push(ast[i]);
            }
            // ast[i] will be -ve here
            else
            {
                // If -ve asteroid has more magnitude
                while (!st.empty() && st.top() > 0 && st.top() < abs(ast[i]))
                {
                    st.pop();
                }

                // If st.top() and ast[i] have same magnitude then pop the element
                // as ast get destroyed
                if (!st.empty() && st.top() == abs(ast[i]))
                {
                    st.pop();
                }

                // If st.top() is also -ve then push the ast[i]
                else {
                    if(st.empty() || st.top() < 0) {
                        st.push(ast[i]);
                    }
                }
            }

        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
