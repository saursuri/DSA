/*
Problem Link: https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long count = 0;
        
        int start = 0, end = n-1;

        while (start <= end)
        {
            if (s[start] == '1' && s[end] == '0')
            {
                swap(s[start], s[end]);
                count += end - start;
                start++;
                end--;
            }
            else if (s[start] == '1' && s[end] == '1')
            {
                end--;
            }
            else if (s[start] == '0' && s[end] == '0')
            {
                start++;
            }
            else
            {
                start++;
                end--;
            }

        }

        return count;
    }
};
