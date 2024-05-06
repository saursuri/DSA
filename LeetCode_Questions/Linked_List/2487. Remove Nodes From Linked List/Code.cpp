/*
Approach: Using Monotonic Stack
Problem Link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *curr = head;
        stack<ListNode*> st;

        while(curr)
        {
            while(!st.empty() && st.top()->val < curr->val)
            {
                st.pop();
            }

            st.push(curr);
            curr = curr->next;
        }
        
        ListNode *nxt = NULL;
        while(!st.empty())
        {
            curr = st.top();
            cout << curr->val << endl;
            st.pop();
            curr->next = nxt;
            nxt = curr;
        }

        return curr;
    }
};
