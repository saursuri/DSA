/*
Problem Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19
Time Complexity: O(3^n)
Space Complexity: O(n)
*/

class Solution {
    int i, k, n;
public:
    bool solve(int j, char prevChar, string &temp, string &ans)
    {
        if (j == n)
        {
            i++;
            if (i == k){
            ans = temp;
            return true; 
            } else {
                return false;
            }   
        }

        for (auto currChar: {'a', 'b', 'c'})
        {
            if (prevChar == '#' || prevChar != currChar)
            {
                temp.push_back(currChar);
                if (solve(j+1, currChar, temp, ans) == true) return true;
                temp.pop_back();
            }
        }

        return false;
    }
    string getHappyString(int n, int k) {
        string temp;
        i=0;
        this->n = n;
        this->k = k;
        string ans;
        solve(0, '#', temp, ans);
        return ans;
    }
};
