/*
Problem Link: https://leetcode.com/problems/rotate-list/
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head==NULL || head->next==NULL) return head;

        // If code reaches here, that means atleast 2 nodes are
        // there in the LL
        ListNode *lastNodePtr = head;
        int length = 1;
        while(lastNodePtr->next)
        {
            length++;
            lastNodePtr = lastNodePtr->next;
        }

        ListNode *prevNodePtr = head;
        int indexToPoint = length - k%length;

        int index = 1;

        while(index!=indexToPoint)
        {
            index++;
            prevNodePtr = prevNodePtr->next;
        }

        lastNodePtr->next = head;
        head = prevNodePtr->next;
        prevNodePtr->next = NULL;

        return head;


    }
};
