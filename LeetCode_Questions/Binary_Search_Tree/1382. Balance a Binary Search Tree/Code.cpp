/*
Problem Link: https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2024-06-26
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
private:
    void inorderTraversal(TreeNode* root, vector<TreeNode *> &sortedArray)
    {
        if (nullptr == root)
        {
            return;
        }
        inorderTraversal(root->left, sortedArray);
        sortedArray.push_back(root);
        inorderTraversal(root->right, sortedArray);
    }

    TreeNode* createBSTfromArray(int left, int right, vector<TreeNode *> &sortedArray)
    {
        if (left > right) return nullptr;

        int mid = left + (right-left)/2;
        TreeNode *root = sortedArray[mid];
        root->left = createBSTfromArray(left, mid-1, sortedArray);
        root->right = createBSTfromArray(mid+1, right, sortedArray);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> sortedArray;
        inorderTraversal(root, sortedArray);
        return createBSTfromArray(0, sortedArray.size()-1, sortedArray);
    }
};
