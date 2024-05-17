/*
Problem Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/?envType=daily-question&envId=2024-05-17
Time Complexity: O(n)
Space Complexity: O(logn) --> Average Case
*/
class Solution {
    void removeLeafNodesUtil(TreeNode* &root, int target)
    {
        if (root==NULL) return;

        removeLeafNodesUtil(root->left,target);
        removeLeafNodesUtil(root->right,target);

        if (!root->left && !root->right && root->val==target)
        {
            root=NULL;
        }

    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (NULL==root) return NULL;
        removeLeafNodesUtil(root,target);
        return root;
    }
};
