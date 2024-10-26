/*
Problem Link: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/?envType=daily-question&envId=2024-10-26
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int level[100001];
    int height[100001];
    int levelMaxHt[100001];
    int levelSecondMaxHeight[100001];

    int findHeight(TreeNode* root, int l)
    {
        if (nullptr == root)
        {
            return 0;
        }

        level[root->val] = l;
        height[root->val] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

        if (levelMaxHt[l] < height[root->val])
        {
            levelSecondMaxHeight[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        }
        else if (levelSecondMaxHeight[l] < height[root->val])
        {
            levelSecondMaxHeight[l] = height[root->val];
        }

        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);
        vector<int> result;

        for (int& node : queries) {
            int L = level[node];

            // L + H - 1

            int tempResult =
                L +
                (levelMaxHt[L] == height[node] ? levelSecondMaxHeight[L]
                                               : levelMaxHt[L]) -
                1;

            result.push_back(tempResult);
        }

        return result;
    }
};
