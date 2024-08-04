/*
Problem Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04
Time Complexity: O(n^2logn)
Space Complexity: O(n^2)
*/
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int modulo = 1e9 + 7;

        int m = (n*(n+1))/2;

        int v[m];

        int sum = 0;
        for (int i=0, k=0; i<n; i++)
        {
            sum = 0;
            for (int j=i; j<n; j++)
            {
                sum = (sum + nums[j]) % modulo;
                v[k++] = sum;
            }
        }

        sort(v, v+m);

        int ans = 0;

        for (int i=left; i<=right; i++)
        {
            ans = (ans + v[i-1]) % modulo;
        }

        return ans;
    }
};
