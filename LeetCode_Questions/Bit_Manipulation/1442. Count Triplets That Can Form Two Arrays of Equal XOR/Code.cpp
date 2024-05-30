/*
Problem Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        int ans=0;

        for(int i=0; i<n; i++)
        {
            int res = 0;
            for(int k=i; k<n; k++)
            {
                res ^= arr[k];
                if (res==0) ans += k-i;
            }
        }

        return ans;
    }
};
