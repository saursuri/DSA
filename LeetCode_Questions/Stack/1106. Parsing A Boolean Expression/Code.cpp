/*
Problem Link: https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;

        int indx = e.length()-1;

        while(indx >= 0)
        {
            if (e[indx] == ')' || e[indx] == 'f' || e[indx] == 't')
            {
                st.push(e[indx]);
            }

            if (e[indx] == '!' || e[indx] == '|' || e[indx] == '&')
            {
                bool ex = (st.top() == 't') ? true:false;
                st.pop();

                if (e[indx] == '!')
                {
                    ex = !ex;
                }
                
                while (st.top() != ')')
                {
                    char top = (st.top() == 't')?true:false;
                    st.pop();

                    if (e[indx] == '|')
                        {
                            ex |= top;
                            cout << "Yes ";
                        }
                    else if (e[indx] == '&')
                        {
                            ex &= top;
                            cout << "No ";
                        }
                    
                }

                st.pop(); // Remove closing bracket
                st.push(ex == true ? 't':'f');

            }

            indx--;

        }

        return (st.top()=='t')?true:false;

    }
};
