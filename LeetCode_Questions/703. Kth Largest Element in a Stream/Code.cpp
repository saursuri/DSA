/*
Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/?envType=daily-question&envId=2024-08-12
Time Complexity: O(nlogk)
Space Complexity: O(k)
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the k largest elements
};
