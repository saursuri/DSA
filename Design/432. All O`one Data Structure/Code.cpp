/*
Problem Link: https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29
Time Complexity: O(1)
Space Complexity: O(k) -> k are no of unique keys
*/

class Node {
public:
    int count;
    unordered_set<string> keys;
    Node* next;
    Node* prev;
    Node(int _count): count(_count), next(nullptr), prev(nullptr) {}
};

class AllOne {
    unordered_map<string, Node*> mp; // maps key to the corresponding Node in the list
    Node* head;
    Node* tail;

    // Helper function to insert a new node with a specific count after a given node
    Node* insertAfter(Node* node, int count) {
        Node* new_node = new Node(count);
        Node* node_next = node->next;
        node->next = new_node;
        new_node->prev = node;
        new_node->next = node_next;
        if (node_next) node_next->prev = new_node;
        return new_node;
    }

    // Helper function to remove a node from the list if it has no keys
    void remove(Node* node) {
        if (node->keys.empty()) {
            Node* node_prev = node->prev;
            Node* node_next = node->next;
            node_prev->next = node_next;
            if (node_next) node_next->prev = node_prev;
            delete node;
        }
    }

public:
    AllOne() {
        head = new Node(0); // Dummy head
        tail = new Node(0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        // Check if the key is already in the map
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->keys.erase(key);

            // If next node has count == node->count + 1, insert key there
            if (node->next == tail || node->next->count > node->count + 1) {
                node->next = insertAfter(node, node->count + 1);
            }
            node->next->keys.insert(key);
            mp[key] = node->next;

            // Remove the node if it has no keys
            remove(node);
        } else {
            // If the key is not in the map, insert it at the first valid node
            if (head->next == tail || head->next->count > 1) {
                head->next = insertAfter(head, 1);
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        }
    }
    
    void dec(string key) {
        if (mp.find(key) == mp.end()) return; // Key doesn't exist

        Node* node = mp[key];
        node->keys.erase(key);

        // If count becomes 0, remove the key from the map
        if (node->count > 1) {
            // Move key to the previous node if it exists, else create a new one
            if (node->prev == head || node->prev->count < node->count - 1) {
                node->prev = insertAfter(node->prev, node->count - 1);
            }
            node->prev->keys.insert(key);
            mp[key] = node->prev;
        } else {
            mp.erase(key); // If count becomes 0, remove it from the map
        }

        // Remove the node if it has no keys
        remove(node);
    }
    
    string getMaxKey() {
        if (tail->prev == head) return ""; // No valid keys
        return *(tail->prev->keys.begin()); // Return any key from the max count group
    }
    
    string getMinKey() {
        if (head->next == tail) return ""; // No valid keys
        return *(head->next->keys.begin()); // Return any key from the min count group
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
