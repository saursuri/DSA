/*
Problem Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19
Time Complexity: O(n)
Space Complexity: O(k) 
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        long long arrSum = 0;

        unordered_map<int, int> hash;
        for (int i=0; i<k; i++)
        {
            arrSum += nums[i];
            hash[nums[i]]++;
        }

        if (hash.size() == k)
            ans = arrSum;

        for (int i=1; i<=n-k; i++)
        {
            hash[nums[i-1]]--;
            if (hash[nums[i-1]] == 0)
                hash.erase(nums[i-1]);
            
            hash[nums[i+k-1]]++;
            arrSum = arrSum - nums[i-1] + nums[i+k-1];
            
            if (hash.size() == k)
            {
                ans = max(arrSum, ans);
            }
        }

        return ans;

    }
};
