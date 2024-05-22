/*
Problem Link: https://leetcode.com/problems/palindrome-partitioning/description/?envType=daily-question&envId=2024-05-22
Time Complexity: O(n*2^n)
Space Complexity: O(n*2^n)
*/

class Solution {
    bool isPalindrome(int i, int index, string &s)
    {
        while(index<=i)
        {
            if (s[index]!=s[i]) return false;
            index++;
            i--;
        }
        return true;
    }
    
    void solve(int index, string &s, vector<string> &currentPartition, vector<vector<string>> &partitions)
    {
        int n = s.length();
        if (index==n)
        {
            partitions.push_back(currentPartition);
            return;
        }

        for(int i=index; i<n; i++)
        {
            if(isPalindrome(i, index, s))
            {
                currentPartition.push_back(s.substr(index,i-index+1));
                solve(i+1, s, currentPartition, partitions);
                currentPartition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;
        vector<string> currentPartition;
        solve(0, s, currentPartition, partitions);

        return partitions;
        
    }
};
