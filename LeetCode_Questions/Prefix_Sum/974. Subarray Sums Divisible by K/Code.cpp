/*
Problem Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/?envType=daily-question&envId=2024-06-09
Time Complexity: O(n)
Space Complexity: O(k)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hash;

        int cummSum = 0, ans=0;
        int remainder;
        hash[0] = 1;
        for(int indx=0; indx<n; indx++)
        {
            cummSum += nums[indx];

            remainder = (cummSum % k);
            remainder = (remainder < 0) ? (remainder + k) : remainder;

            if (hash.count(remainder))
                ans += hash[remainder];

            hash[remainder]++;

        }

        return ans;

    }
};
