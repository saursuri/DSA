/*
Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/?envType=daily-question&envId=2024-05-05
Time Complexity: O(1)
Space Complexity: O(1)
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Approach: Instead of deleting the currentNode
        // Copy value from next node and delete the next node
        ListNode *ptr = node->next;

        node->val = ptr->val;
        node->next = ptr->next;

        ptr->next = NULL;
        delete(ptr);
    }
};
