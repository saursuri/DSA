/*
Problem Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/?envType=daily-question&envId=2025-02-22
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    string traversal;
    int i;
    
    // Extracts the next node's value from the traversal string
    int findNode() {   
        string nodeVal;
        while (i < traversal.length() && traversal[i] != '-') {
            nodeVal.push_back(traversal[i]);
            i++;
        }
        return stoi(nodeVal);
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        this->traversal = traversal;
        i = 0;
        
        unordered_map<int, TreeNode*> levelMap;
        
        TreeNode* root = new TreeNode(findNode());
        levelMap[0] = root;

        while (i < traversal.length()) {
            int level = 0;
            
            // Count the number of dashes to determine the depth
            while (i < traversal.length() && traversal[i] == '-') {
                level++;
                i++;
            }

            TreeNode* newNode = new TreeNode(findNode());

            // Attach the new node to the appropriate parent
            TreeNode* parent = levelMap[level - 1];
            if (!parent->left) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }

            // Update the latest node at the current level
            levelMap[level] = newNode;
        }
        
        return root;
    }
};
