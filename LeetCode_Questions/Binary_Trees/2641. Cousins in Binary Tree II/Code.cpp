/*
Problem Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> levelSum;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            long long tempSum = 0;

            for(int i=0; i<n; i++)
            {
                auto qFront = q.front();
                q.pop();

                tempSum += qFront->val;

                if (qFront->left) q.push(qFront->left);
                if (qFront->right) q.push(qFront->right);
            }

            levelSum.push_back(tempSum);

        }

        q.push(root);
        int level = 0;

        queue<int> pairQ;
        pairQ.push(root->val);

        while(!q.empty())
        {
            int n = q.size();

            for(int i=0; i<n; i++)
            {
                auto qFront = q.front();
                q.pop();

                qFront->val = levelSum[level] - pairQ.front();

                pairQ.pop();
                
                int pairSum = 0;
                if (qFront->left)
                { 
                    q.push(qFront->left);
                    pairSum += qFront->left->val;
                }
                if (qFront->right) 
                {
                    q.push(qFront->right);
                    pairSum += qFront->right->val;
                }

                if (qFront->left)
                    pairQ.push(pairSum);
                
                if (qFront->right)
                    pairQ.push(pairSum);
            }

            level++;
        }


        return root;

    }
};
