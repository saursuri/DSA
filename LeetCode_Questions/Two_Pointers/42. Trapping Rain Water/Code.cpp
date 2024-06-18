/*
Problem Link: https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n-1;
        int leftBuilding = 0, rightBuilding = 0;
        int waterStored = 0;
        while(left <= right)
        {
            if (height[left] <= height[right])
            {
                if (leftBuilding <= height[left])
                    leftBuilding = height[left];
                else 
                    waterStored += leftBuilding - height[left];
                
                left++;
            }
            else
            {
                if (rightBuilding <= height[right])
                    rightBuilding = height[right];
                else 
                    waterStored += rightBuilding - height[right];
                
                right--;
            }
        }

        return waterStored; 
    }
};
