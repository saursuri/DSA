/*
Problem Link: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/
Approach: Priority Queue
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
#define iPair pair<char, int>

struct CustomCompare {
    bool operator()(const iPair& lhs, const iPair& rhs) const {
        if (lhs.first == rhs.first) return lhs.second < rhs.second;

        return lhs.first > rhs.first;
    }
};

class Solution {
public:
    string clearStars(string s) {
        
        priority_queue<iPair, vector<iPair>, CustomCompare> pq;
        int n = s.length();

        for (int i=0; i< n; i++)
        {
            if (s[i] != '*')
                pq.push({s[i], i});

            if (s[i] == '*')
            {
                auto topElem = pq.top();
                pq.pop();

                s[topElem.second] = '*';
            }
        }

        string ans;
        for(auto ch: s)
        {
            if (ch == '*') continue;
            ans.push_back(ch);
        }

        return ans;

    }
};
