/*
Problem Link: https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    static bool canChange(string& s, string& t) {
        const int n=s.size();
        for(int i=0, j=0; i<n || j<n; i++, j++){
            while(i<n && s[i]=='_') i++;
            while(j<n && t[j]=='_') j++;
        
            char c=s[i];
            if (c !=t[j]) return 0;
            if (c =='L' && i<j) return 0;
            if (c =='R' && i>j) return 0;
        }
        return 1;
    }
};
