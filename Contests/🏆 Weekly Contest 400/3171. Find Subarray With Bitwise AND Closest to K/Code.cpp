/*
Problem Link: https://leetcode.com/problems/find-subarray-with-bitwise-and-closest-to-k/description/
Approach: Binary Search + Segment Tree
Time Complexity: O(n * logn * logn + n) 
Space Complexity: O(4*n) --> Segment tree nodes
*/
class segmentTree {
private:
    int tree[4*100000]; // Using vector will be slower therefore used constraints
    int n;

    int buildTree(int node, int left, int right, vector<int>& nums) {
        if (left == right) {
            return tree[node] = nums[left];
        }

        int mid = (left + right) >> 1;
        return tree[node] = buildTree(2 * node + 1, left, mid, nums) // For Left node
        & buildTree(2 * node + 2, mid + 1, right, nums); // For Right node

    }

    int queryTree(int node, int left, int right, int qleft, int qright) {
        // If query range in search range
        if (left >= qleft && right <= qright)
            return tree[node];

        if (right < qleft || left > qright)
            return - 1; // Identity for AND operation

        int mid = (left + right) / 2;
        return queryTree(2 * node + 1, left, mid, qleft, qright) &
               queryTree(2 * node + 2, mid + 1, right, qleft, qright);
    }

public:
    segmentTree(vector<int>& nums) {
        n = nums.size();
        buildTree(0, 0, n - 1, nums);
    }

    int queryTree(int qleft, int qright)
    {
        return queryTree(0, 0, n-1, qleft, qright);
    }


};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        // Time Complexity: O(n) to build the segment Tree
        segmentTree tree(nums);

        int minDiff = 1e9;

        // Time Complexity: O(n) for the outer loop
        for (int left = 0; left < n; left++) {
            int low = left, high = n - 1;

            // Time Complexity: O(logn) for the Binary Search
            while (low <= high) {
                int right = (low + high) / 2;

                // Time Complexity: O(logn) for the Segment Tree Query operation
                int subarrayAND = tree.queryTree(left, right);

                minDiff = min(minDiff, abs(k - subarrayAND));

                if (subarrayAND == k) return minDiff;
                else if (subarrayAND < k) high = right - 1;
                else low = right + 1;
            }
        }

        return minDiff;
    }
};
