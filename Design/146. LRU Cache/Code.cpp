/*
Problem Link: https://leetcode.com/problems/lru-cache/
Time Complexity: O(1)
Space Complaxity: O(capacity)
*/

class doubleLL {
public:
    int key;
    int value;
    doubleLL* prev;
    doubleLL* next;

    doubleLL(int key, int value) {
        this->key = key;
        this->value = value;

        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    doubleLL* head = new doubleLL(-1, -1);
    doubleLL* tail = new doubleLL(-1, -1);
    int capacity;
    unordered_map<int, doubleLL*> mp;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    void deleteNode(doubleLL* node) {
        doubleLL* prevNode = node->prev;
        doubleLL* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

    }

    void addNode(doubleLL* node) {
        doubleLL* nextNode = head->next;

        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {
        // Check if key is present in map
        if (mp.count(key)) {
            doubleLL* node = mp[key];

            mp.erase(key);

            // Delete the node from the LL
            deleteNode(node);

            // Add node to the LL to make it recently used
            addNode(node);

            // Update the mp with updated value
            mp[key] = head->next;

            return node->value;
        }

        // If key not present
        return -1;
    }

    void put(int key, int value) {

        // Check if key already present
        if (mp.count(key)) {
            
            // Need to update the key with new value
            doubleLL* node = mp[key];

            mp.erase(key);
            
            // Delete the node
            deleteNode(node);
        }

        // If capacity becomes full
        if (mp.size() == capacity) {
            // Erase the last key from map
            mp.erase(tail->prev->key);

            deleteNode(tail->prev);
        }

        // add new node
        doubleLL* newNode = new doubleLL(key, value);
        addNode(newNode);

        // Update the map
        mp[key] = head->next;
    }
};
