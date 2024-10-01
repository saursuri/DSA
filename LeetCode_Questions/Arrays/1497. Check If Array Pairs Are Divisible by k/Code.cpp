/*
Problem Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        multiset<int> hash;
        int zeros_count = 0;

        for (auto &it : arr)
        {
            int x = ((it%k)+k) % k;  // Ensure x is non-negative
            int y = (x == 0) ? 0 : k - x;  // Handle when x is 0 separately
            
            auto &&i = hash.find(y);

            if (x == 0) zeros_count++;

            // Check if y is in hash
            if (i != hash.end())
            {
                // Remove y
                hash.erase(i);
            }
            else
            {
                hash.insert(x);
            }
        }

        // Check if all pairs were matched
        if (hash.size() == 0 || zeros_count == hash.size()) {
            return true;
        }
        
        return false;
    }
};
