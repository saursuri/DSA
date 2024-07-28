/*
Problem Link: https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/?envType=daily-question&envId=2024-07-28
Time Complexity: O(V+E)
Space Compexity: O(V+E)
*/

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> adjList[n+1];

        for(auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int dist1[n+1], dist2[n+1];
        fill(dist1, dist1+n+1, INT_MAX);
        fill(dist2, dist2+n+1, INT_MAX);

        queue<pair<int,int>> q;
        q.push({1,1}); // Node 1 with freq 1
        dist1[1] = 0;

        while(!q.empty())
        {
            auto [node, freq] = q.front();
            q.pop();

            int timePassed = (freq==1) ? dist1[node] : dist2[node];

            if (node == n && dist2[node] != INT_MAX)
                return dist2[node];
            
            int div = timePassed / change;
            if (div % 2 == 1)
            {
                timePassed = (div+1)*change;
            }

            for (auto &neighbor: adjList[node])
            {
                if (dist1[neighbor] == INT_MAX)
                {
                    dist1[neighbor] = timePassed + time;
                    q.push({neighbor,1});
                }
                else if (dist2[neighbor] == INT_MAX && dist1[neighbor] != timePassed + time)
                {
                    dist2[neighbor] = timePassed + time;
                    q.push({neighbor,2});
                }
            }
        }

        return -1;

    }
};
