/*
Problem Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (nullptr == head) return nullptr;
        ListNode * newHead = nullptr;
        ListNode * ptr = head;

        int nodeVal = 0;
        ListNode * new_node = nullptr;
        while(ptr->next != nullptr)
        {
            if (ptr->val == 0)
            {
                nodeVal = 0;
                
                if (new_node == nullptr)
                {
                    new_node = new ListNode();
                    newHead = new_node;
                }
                else
                {
                    new_node->next = new ListNode();
                    new_node = new_node->next;
                }
            }
            else
            {
                nodeVal += ptr->val;
                new_node->val = nodeVal;
            }

            ptr = ptr->next;
        }

        if (nullptr != new_node)
            new_node->next = nullptr;

        return newHead; 

    }
};
