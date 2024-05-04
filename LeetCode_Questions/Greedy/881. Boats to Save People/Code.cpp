/*
Problem Link: https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());
        int n = people.size();

        int boats = 0;
        int left = 0, right = n - 1;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit)
                left++;

            boats++;
            right--;
        }

        return boats;
    }
};
