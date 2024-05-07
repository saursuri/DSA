/*
Problem Link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode *> st;
        ListNode *ptr = head;
        
        while(ptr)
        {   
            st.push(ptr);
            ptr = ptr->next;
        }

        int carry = 0;
        while(!st.empty())
        {
            int caln = st.top()->val * 2 + carry;

            int newNodeVal = caln%10;

            st.top()->val = newNodeVal;
            st.pop();
            carry = caln/10;

        }
        
        if (carry!=0)
        {
            ListNode *newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};
