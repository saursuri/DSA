/*
Problem Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (nullptr == head) return head;

        ListNode* ptr = head;
        while(ptr->next)
        {
            int val = __gcd(ptr->val, ptr->next->val);
            ListNode* new_node = new ListNode(val);

            ListNode* next_node = ptr->next;
            ptr->next = new_node;
            new_node->next = next_node;

            ptr = next_node;
        }

        return head;
    }
};
