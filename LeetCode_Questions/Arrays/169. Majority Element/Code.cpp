/*
Problem Link: https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majElement = nums[0];
        int occurences = 1;

        int indx = 1, n = nums.size();

        while (indx < n)
        {
            if (nums[indx] == majElement)
            {
                occurences++;
            }
            else
            {
                occurences--;

                if (occurences == 0)
                {
                    majElement = nums[indx];
                    occurences = 1;
                }
            }

            indx++;
        }

        return majElement;
    }
};
