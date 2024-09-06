/*
Problem Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        ListNode* prev = nullptr;  // Pointer to track the last valid node
        ListNode* temp = head;     // Pointer to traverse the list
        ListNode* newHead = nullptr; // Pointer to track the new head of the list

        while (temp) {
            if (!st.count(temp->val)) {
                if (newHead == nullptr) {
                    newHead = temp;  // Set new head if it hasn't been set yet
                }
                prev = temp;  // Update prev to the current node
            } else if (prev) {
                prev->next = temp->next;  // Bypass the current node
            }

            // Move to the next node
            ListNode* nextNode = temp->next;

            // If current node is to be deleted, free memory
            if (st.count(temp->val)) {
                delete temp;
            }

            temp = nextNode;  // Proceed to next node
        }

        return newHead;
    }
};
