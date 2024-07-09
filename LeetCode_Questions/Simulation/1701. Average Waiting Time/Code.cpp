/*
Problem Link: https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double waitingTime = 0;
        int currentTime = 0;
        for (auto &customer: customers)
        {
            currentTime = max(currentTime, customer[0]) + customer[1];
            waitingTime += currentTime - customer[0];
        }

        return waitingTime/n;
    }
};
