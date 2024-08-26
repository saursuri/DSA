/*
Problem Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/?envType=daily-question&envId=2024-08-26
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
private:
    void post_order_traversal(Node* root, vector<int> &ans)
    {
        if (nullptr == root) return;

        for (auto node: root->children)
        {
            post_order_traversal(node, ans);
        }

        ans.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        
        vector<int> ans;
        post_order_traversal(root, ans);
        return ans;
    }
};
