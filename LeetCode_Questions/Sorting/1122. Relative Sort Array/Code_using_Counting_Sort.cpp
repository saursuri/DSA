/*
Problem Link: https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
Time Complexity: O(n + m + k) --> k the range between min and max element
Space Complexity: O(n + hashSpace)
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int minElement = *min_element(arr1.begin(), arr1.end());
        int maxElement = *max_element(arr1.begin(), arr1.end());

        unordered_map<int, int> freqHash;

        for (auto nums: arr1) freqHash[nums]++;

        vector<int> ans;

        for(auto nums: arr2)
        {
            while (freqHash[nums] > 0)
            {
                ans.push_back(nums);
                freqHash[nums]--;
            }
        }

        for(int i=minElement; i<=maxElement; i++)
        {
            while (freqHash[i] > 0)
            {
                ans.push_back(i);
                freqHash[i]--;
            }
        }


        return ans;
    }
};
