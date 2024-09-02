/*
Problem Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;

        for (auto &it: chalk) sum += it;

        k = k%sum;

        int n = chalk.size();
        for (int i=0; i<n; i++)
        {
            if (k < chalk[i])
            {
                return i;
            }
            else
            {
                k -= chalk[i];
            }
        }

        return -1;

    }
};
