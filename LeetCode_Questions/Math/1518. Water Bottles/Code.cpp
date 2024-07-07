/*
Problem Link: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
Time Complexity: O(log(numBottles))
Space Complexity: O(1)
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles = numBottles;
        int emptyBottles = numBottles;
        numBottles = 0;
        

        while (numBottles != 0 || emptyBottles >= numExchange)
        {
            numBottles = emptyBottles / numExchange;
            emptyBottles = numBottles + emptyBottles % numExchange;
            totalBottles += numBottles;
        }

        return totalBottles;

    }
};
