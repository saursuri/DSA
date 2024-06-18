/*
Problem Link: https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
Time Complexity: O(n)
Space Complexity: O(13)
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash =
        {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        unordered_map<string, int> hash2 =
        {{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};

        int ans = 0;
        
        int n = s.length();
        int indx = 0;

        while(indx < n)
        {
            string temp = s.substr(indx,2);
            if (hash2.count(temp))
            {
                ans += hash2[temp];
                indx += 2;
            }
            else 
            {
                ans += hash[s[indx]];
                indx++;
            }
        }

        return ans;
    }
};
