/*
Problem Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
private:
    bool findPath(TreeNode *root, int val, string &path)
    {
        if (nullptr == root) return false;
        
        if (val == root->val) return true;

        path.push_back('L');
        if (findPath(root->left, val, path) == true) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, val, path) == true) return true;
        path.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string rootToSource, rootToDest;

        findPath(root, startValue, rootToSource);
        findPath(root, destValue, rootToDest);

        int l=0;
        while (l < rootToSource.length() && l < rootToDest.length() && rootToSource[l] == rootToDest[l])
        {
            l++;
        }

        string ans;

        for (int i=l; i<rootToSource.length(); i++)
        {
            ans.push_back('U');
        }

        for(int i=l; i<rootToDest.length(); i++)
        {
            ans.push_back(rootToDest[i]);
        }

        return ans;

    }
};
