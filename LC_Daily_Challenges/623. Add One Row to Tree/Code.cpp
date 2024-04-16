/*
Time Complexity: O(n)
Space Complexity: O(h)
*/

class Solution {
public:
TreeNode* addOneRow(TreeNode* root, int val, int depth) {

	// This is the Case when depth is 1
	if (depth == 1) {
		// Create a new node
		TreeNode* newNode = new TreeNode(val);
		// Attach root node to left subTree of newNode
		newNode->left = root;
		// Return the newNode as this is the new Tree root
		return newNode;
	}

	// Create Queue for BFS Traversal
	queue<TreeNode*> q;

	// Push the node
	q.push(root);

	// Keep track of the depth
	int localDepth = 0;
	
	while (!q.empty()) {
		// Get the Queue Size
		int qSize = q.size();
		// At this point we move to next level so increase the localDepth
		localDepth++;
	
		for (int i = 0; i < qSize; i++) {
			// Store front of node in a variable and pop the node from Queue
			TreeNode* frontNode = q.front();
			q.pop();
	
			// If localDepth matches with the given depth
			if (localDepth == depth - 1) {
				// Create two nodes leftNode and rightNode
				TreeNode* leftNode = new TreeNode(val);
				TreeNode* rightNode = new TreeNode(val);

				// Attach leftNode and rightNode in between current depth
				leftNode->left = frontNode->left;
				rightNode->right = frontNode->right;

				// Attach leftNode and rightNode in between current depth
				frontNode->left = leftNode;
				frontNode->right = rightNode;
			}

			// If Left node exist, push left node
			if (frontNode->left)
				q.push(frontNode->left);

			// If right node exist, push right node
			if (frontNode->right)
				q.push(frontNode->right);
			
		}
	}
	
	return root;
}
};

