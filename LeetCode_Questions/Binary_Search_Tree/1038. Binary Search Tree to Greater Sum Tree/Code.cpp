/*
Problem Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25
Time Complexity: O(n)
Space Complexity: O(h) --> Height of the BST
*/

class Solution {
    void solve(TreeNode * root, int &sum)
    {
        if (nullptr == root) return;

        solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        solve(root->left, sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        solve(root, sum);

        return root;
    }
};
