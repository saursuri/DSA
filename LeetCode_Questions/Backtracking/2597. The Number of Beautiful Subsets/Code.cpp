/*
Problem Link: https://leetcode.com/problems/the-number-of-beautiful-subsets/description/?envType=daily-question&envId=2024-05-23
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
class Solution {
private:
    int beautifulSubsetsUtil(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) { // base case
            return 1;
        }
        int result = beautifulSubsetsUtil(nums, k, freq, i + 1); // nums[i] not taken
        if (!freq[nums[i] - k] && !freq[nums[i] + k]) { // check if we can take nums[i]
            freq[nums[i]]++;
            result += beautifulSubsetsUtil(nums, k, freq, i + 1); // nums[i] taken
            freq[nums[i]]--;
        }
        return result;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        return beautifulSubsetsUtil(nums, k, freq, 0) - 1; // -1 for empty subset
    }
};
