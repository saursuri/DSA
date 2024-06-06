/*
Problem Link: https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06
Time Complexity: O(nlogn + hashSize * groupSize)
Space Complexity: O(no. of distinct elements in hand)
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> hash;

        for(auto card: hand)
        {
            hash[card]++;
        }

        for(auto it: hash)
        {
            int startCard = it.first;
            int count = it.second;

            // If there are any cards of this type
            if (count > 0) {
                // Try to form a group starting with this card
                for (int i = 0; i < groupSize; i++) {
                    // Check if next card doesn't exist return false
                    if (hash[startCard + i] < count) {
                        return false;
                    }
                    // Decrement count 
                    hash[startCard + i] -= count;
                }
            }
        }

        return true;
    }
};
