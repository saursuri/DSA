/*
Problem Link: https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if (k==0 || n<2) return false;

        // Store preSum as key and index as value
        unordered_map<int,int> hash;
        int runningSum = 0;

        hash[0] = -1;
        for(int i=0; i<n; i++)
        {
            runningSum = (runningSum + nums[i])%k;
            
            if (hash.count(runningSum) && (i-hash[runningSum])>1)
            {
                return true;
            }
            else if(!hash.count(runningSum))
                hash[runningSum] = i;
        }

        return false;
    }
};
