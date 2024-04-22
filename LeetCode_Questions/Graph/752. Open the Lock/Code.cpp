/*
Problem Link: https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22
Time Complexity: O(10000)
Space Complexity: O(10000) --> Queue and set at max will store all the combinations 
*/
class Solution {
public:
    typedef pair<string, int> iPair;
    vector<string> getNeighbors(string node) {
        vector<string> ans;

        for (int i = 0; i < 4; i++) {
            string up = node;
            string down = node;
            up[i] = (up[i] - '0' + 1) % 10 + '0';
            down[i] = (10 + down[i] - '0' - 1) % 10 + '0';
            ans.push_back(up);
            ans.push_back(down);
        }

        return ans;
    }

    int openLock(vector<string>& deadends, string target) {

        queue<iPair> q;

        // Steps required for initial config
        q.push({"0000", 0});

        // Unordered set to stop BFS from visiting deadends and already visited
        // configs
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000"))
            return -1;

        // BFS Traversal
        while (!q.empty()) {
            auto elem = q.front();
            q.pop();

            string node = elem.first;
            int steps = elem.second;

            if (node == target)
                return steps;

            // Visit neighbors
            for (auto neighbor : getNeighbors(node)) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push({neighbor, steps + 1});
                }
            }
        }

        return -1;
    }
};
