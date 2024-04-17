/*
Problem Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/description/?envType=daily-question&envId=2024-04-17

Time Complexity: O(n) --> n represents the number of nodes, since all nodes are visited during DFS
Space Complexity: O(h) --> h represents height of tree, this is due to recursion Stack
*/

class Solution {
  public:
    void findUsingDFS(TreeNode* root, string &ans, string temp)
    {   
      // If root is NULL return
      if(root==NULL) return;
      
      // If leaf node
      if(root->left==NULL && root->right==NULL)
      {   
        // Push the leaf node to temp string
        temp.push_back(root->val+'a');
        
        // Reverse the string
        reverse(temp.begin(),temp.end());
        
        // We need lexicographically smaller so compare ans with temp
        // If temp is smaller than update ans
        if(ans.empty() || ans>temp)
        ans = temp;
        
        return;
      }   
      
      // Push string till leaf nodes, leaf nodes will be pushed in above if statement
      temp.push_back(root->val+'a');
      
      // Visit left and right sub-tree
      findUsingDFS(root->left,ans,temp);
      findUsingDFS(root->right,ans,temp);
      
      
      }
      string smallestFromLeaf(TreeNode* root) {
      
        // String ans to store the ans
        string ans;
        
        // Find using DFS
        findUsingDFS(root,ans,"");
        
        return ans;
    }
};
