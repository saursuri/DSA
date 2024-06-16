/*
Problem Link: https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(m+n)
Space Complexity: O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int indx1 = m-1, indx2 = n-1;

        while(indx1 >=0 && indx2 >=0)
        {
            if (nums2[indx2] > nums1[indx1])
            {
                nums1[indx1 + indx2 + 1] = nums2[indx2];
                indx2--;
            }
            else
            {
                nums1[indx1 + indx2 + 1] = nums1[indx1];
                indx1--;
            }
        }

        while (indx1 >= 0) 
        {
            nums1[indx1 + indx2 + 1] = nums1[indx1];
            indx1--;
        }
        
        while (indx2 >= 0) 
        {
            nums1[indx1 + indx2 + 1] = nums2[indx2];
            indx2--;
        }
    }
};
