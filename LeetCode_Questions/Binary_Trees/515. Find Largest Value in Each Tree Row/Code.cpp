/*
Problem Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/?envType=daily-question&envId=2024-12-25
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if (root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int qSize = q.size();
            int levelMax = INT_MIN;

            for (int i=0; i<qSize; i++)
            {
                auto qFront = q.front();
                q.pop();

                levelMax = max(levelMax, qFront->val);

                if (qFront->left) q.push(qFront->left);
                if (qFront->right) q.push(qFront->right);


            }

            ans.push_back(levelMax);
        }


        return ans;
    }
};
