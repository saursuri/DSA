/*
Problem Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            long long localSum = 0;

            for (int i = 0; i < size; i++) {
                auto qFront = q.front();
                q.pop();

                localSum += qFront->val;

                if (qFront->left)
                    q.push(qFront->left);
                if (qFront->right)
                    q.push(qFront->right);
            }

            levelSum.push_back(localSum);
        }

        if (levelSum.size() < k)
            return -1;

        sort(levelSum.begin(), levelSum.end(),
             [](long long& a, long long& b) { return a > b; });

        return levelSum[k - 1];
    }
};
