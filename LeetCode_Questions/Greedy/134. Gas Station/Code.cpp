/*
Problem Link: https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gasAtIndx = 0;
        int totalAccumGas = 0;
        int gasDiff = 0;
        int indx = 0;
        for (int i=0; i<n; i++)
        {
            gasAtIndx = gas[i] - cost[i];
            gasDiff += gasAtIndx;
            totalAccumGas += gasAtIndx;

            if (totalAccumGas < 0)
            {
                indx = i + 1;
                totalAccumGas = 0;
            }

        }

        return gasDiff >=0 ? indx : -1;
    }
};
