/*
Problem Link: https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (nullptr == head) return head;

        ListNode* leftPrev = nullptr;
        ListNode* curr = head;

        for(int i = 1; i < left; i++) {
            leftPrev = curr;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        ListNode* nxtNode = nullptr;
        ListNode* connection = curr;
        
        for(int i = left; i <= right; i++) {
            nxtNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxtNode;
        }

        if (leftPrev) {
            leftPrev->next = prev;
        } else {
            head = prev; 
        }

        connection->next = curr;

        return head;
    }
};
