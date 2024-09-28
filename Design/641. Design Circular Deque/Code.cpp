/*
Problem Link: https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28
Time Complexity: O(1)
Space Complexity: O(1)
*/

class dll{
    public:
        int val;
        dll* next;
        dll* prev;
        dll(int _val):val(_val),next(nullptr), prev(nullptr){}
};

class MyCircularDeque {
    dll* head;
    dll* tail;
    int maxSize, currSize;
public:
    MyCircularDeque(int k):maxSize(k),currSize(0) {
        head = new dll(-1);
        tail = new dll(-1);

        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) {
        if (currSize < maxSize)
        {
            // Insert the node at front
            dll* next_node = head->next;

            dll* new_node = new dll(value);

            head->next = new_node;
            new_node->next = next_node;
            next_node->prev = new_node;
            new_node->prev = head;

            currSize++;
            return true;
        }

        return false;
    }
    
    bool insertLast(int value) {
        if (currSize < maxSize)
        {
            // Insert node at the end
            dll* prev_node = tail->prev;

            dll* new_node = new dll(value);

            tail->prev = new_node;
            new_node->prev = prev_node;

            prev_node->next = new_node;
            new_node->next = tail;

            currSize++;
            return true;
        }

        return false;
    }
    
    bool deleteFront() {
        if (currSize > 0)
        {
            // Delete from the front
            dll* to_delete = head->next;

            dll* next_node = to_delete->next;

            head->next = next_node;
            next_node->prev = head;

            to_delete->next = nullptr;
            to_delete->prev = nullptr;

            delete to_delete;
            currSize--;

            return true;
        }

        return false;
    }
    
    bool deleteLast() {
        if (currSize > 0)
        {
            // Delete from the last
            dll* to_delete = tail->prev;

            dll* prev_node = to_delete->prev;

            tail->prev = prev_node;
            prev_node->next = tail;

            to_delete->next = nullptr;
            to_delete->prev = nullptr;

            delete to_delete;
            currSize--;

            return true;
        }

        return false; 
    }
    
    int getFront() {
        if (currSize>0)
        {
            return head->next->val;
        }
        return -1;
    }
    
    int getRear() {
        if (currSize>0) return tail->prev->val;
        return -1;
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize==maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
