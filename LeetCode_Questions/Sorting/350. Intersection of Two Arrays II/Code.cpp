/*
Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02
Time Complexity: O(max(n,m)log(max(n,m)))
Space Complexity: O(max(n,m))
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int index1 = 0,index2=0;

        vector<int> ans;

        // Loop till one or both of indexes are less than array size
        while(index1<n1 && index2<n2)
        {
            // Compare value at index1 and index2
            if(nums1[index1]==nums2[index2])
            {
                //if(ans.size()==0 || ans.back()!=nums1[index1])
                    ans.push_back(nums1[index1]);

                index1++;
                index2++;
            }
            else if (nums1[index1]<nums2[index2])
            {
                index1++;
            }
            else
            {
                index2++;
            }
        }
        return ans;  
    }
};
