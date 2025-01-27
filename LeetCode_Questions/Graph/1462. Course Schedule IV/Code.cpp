/*
Problem Link: https://leetcode.com/problems/course-schedule-iv/?envType=daily-question&envId=2025-01-27
Time Complexity: O(V^2 + E + Q)
Space Complexity: O(V^2 + E + Q)
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses, 0);
        vector<int> adjList[numCourses];
        for (auto &it : prereq)
        {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }

        vector<unordered_set<int>> dependency(numCourses);
        vector<bool> ans;
        queue<int> q;
        
        for (int node=0; node < numCourses; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
                dependency[node].insert(-1);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            // Visit nbrs
            for (auto &nbr: adjList[node])
            {
                dependency[nbr].insert(node);
                for (auto &it: dependency[node])
                {
                    dependency[nbr].insert(it);
                }
                
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        for (auto &qry: queries)
        {
            int u = qry[0];
            int v = qry[1];

            if (dependency[v].count(u))
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }

        return ans;
    }
};
