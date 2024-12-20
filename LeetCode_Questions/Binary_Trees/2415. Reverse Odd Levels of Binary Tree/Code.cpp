/*
Problem Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20
Time Complexity: O(number of nodes)
Space Complexity: O(number of nodes)
*/

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        int level = 0;
        vector<TreeNode*> levelInfo;
        q.push(root);
        levelInfo.push_back(root);

        while(!q.empty())
        {
            int qSize = q.size();

            if (level%2==1)
            {
                int l=0;
                int r=levelInfo.size()-1;
                while(l<=r)
                {
                    swap(levelInfo[l]->val, levelInfo[r]->val);
                    l++;
                    r--;
                }
            }

            levelInfo.clear();

            for (int i=0; i<qSize; i++)
            {
                auto top = q.front();
                q.pop();

                if(top->left)
                {
                    q.push(top->left);
                    levelInfo.push_back(top->left);
                }
                
                if(top->right)
                {
                    q.push(top->right);
                    levelInfo.push_back(top->right);
                }
            }

            level++;
        }

        return root;
    }
};
