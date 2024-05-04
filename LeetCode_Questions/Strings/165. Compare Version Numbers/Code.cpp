/*
Problem Link: https://leetcode.com/problems/compare-version-numbers/description/
Time Complexity: O(m+n)
Space Complexity: O(m+n)
*/

class Solution {
public:
    vector<int> getTokens(string version)
    {
        stringstream ss(version);
        string token = "";

        vector<int> tokens;
        while(getline(ss,token,'.'))
        {
            tokens.push_back(stoi(token));
        }

        return tokens;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = getTokens(version1);
        vector<int> v2 = getTokens(version2);

        int m = v1.size();
        int n = v2.size();

        int index = 0;

        while(index<m || index<n)
        {
            int a = index<m?v1[index]:0;
            int b = index<n?v2[index]:0;

            if (a<b) return -1;
            if (b<a) return 1;
            else index++;
        }

        return 0;
        
    }
};
