/*
Problem Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18
Time Complexity: O(n)
Space Complexity: O(depth of the tree) --> Average O(logn) --> Worst O(n) [Skewed Tree]
*/
class Solution {
    int distributeCoinsUtil(TreeNode *root,int &moves)
    {
        if(root==NULL) return 0;

        // Post order DFS
        int leftExtraCoins = distributeCoinsUtil(root->left, moves);
        int rightExtraCoins = distributeCoinsUtil(root->right, moves);

        moves+=abs(leftExtraCoins) + abs(rightExtraCoins);
        
        // Doing -1 as 1 coin will be taken by child
        return (leftExtraCoins + rightExtraCoins + root->val) - 1;

    }
    
public:
    int distributeCoins(TreeNode* root) {
        int moves=0;
        distributeCoinsUtil(root, moves);

        return moves;
    }
};
