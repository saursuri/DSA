/*
Problem Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/?envType=daily-question&envId=2024-05-16
Time Complexity: O(n)
Space Complexity: O(logn)
*/

class Solution {
private:
    bool evaluateTreeUtil(TreeNode* root)
    {
        if (!root->left && !root->right) return root->val;

        bool left = evaluateTreeUtil(root->left);
        bool right = evaluateTreeUtil(root->right);

        if(root->val==2)
            return left|right;
        else
            return left&right;
    }

public:
    bool evaluateTree(TreeNode* root) {
        return evaluateTreeUtil(root);
    }
};
