/*
Problem Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15
Time Complexity: O(N*logN)
Space Complexity: O(N)
*/

class ds {
public:
    double ratio;
    int num;
    int den;
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // Comparator for max-heap (prioritize largest ratio difference)
        auto compare = [](ds& d1, ds& d2) {
            return d1.ratio < d2.ratio; // Max-heap: prioritize larger ratio differences
        };

        // Priority queue with custom comparator
        priority_queue<ds, vector<ds>, decltype(compare)> pq(compare);

        // Initialize the priority queue with ratio differences
        for (auto& it : classes) {
            double newRatio = (double(it[0]) + 1.0) / (double(it[1]) + 1.0);
            double oldRatio = double(it[0]) / double(it[1]);
            double ratioDiff = newRatio - oldRatio;
            pq.push({ratioDiff, it[0], it[1]});
        }

        // Distribute extra students
        while (extraStudents > 0) {
            extraStudents--;
            auto pqTop = pq.top();
            pq.pop();

            // Update the class with one extra student
            pqTop.num += 1;
            pqTop.den += 1;

            double newRatio = (double(pqTop.num) + 1.0) / (double(pqTop.den) + 1.0);
            double oldRatio = double(pqTop.num) / double(pqTop.den);
            pqTop.ratio = newRatio - oldRatio;

            pq.push(pqTop);
        }

        // Calculate the final average pass ratio
        double ans = 0.0;
        while (!pq.empty()) {
            ans += double(pq.top().num) / pq.top().den;
            pq.pop();
        }

        return ans / n;
    }
};
