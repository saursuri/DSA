/*
Problem Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21
Time Complexity: O(n)
Space Complexity: O(n)
*/

class FindElements {
    unordered_set<int> st;
    void recover_tree(TreeNode* root){
        if (nullptr == root) return;
        
        st.insert(root->val);

        if (root->left)
        {   
            root->left->val = root->val * 2 + 1;
            recover_tree(root->left);
        }
        if (root->right)
        {
            root->right->val = root->val * 2 + 2;
            recover_tree(root->right);
        }

        return;
    }

public:
    FindElements(TreeNode* root) {
        root->val = 0;
        recover_tree(root);
    }
    
    bool find(int target) {
        if (st.count(target))
            return true;
        else return false;    
    }
};
