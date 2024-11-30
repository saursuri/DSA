/*
Problem Link: https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=daily-question&envId=2024-11-30
Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        int edges = pairs.size();
        vector<vector<int>> ans;

        // Create graph in for of adjacency List
        unordered_map<int, vector<int>> adjList;

        // Create Indegree and outdegree of nodes
        unordered_map<int,int> indegree,outdegree;

        // Create Graph
        for(auto &it: pairs)
        {
            int u = it[0];
            int v = it[1];

            indegree[v]++;
            outdegree[u]++;

            adjList[u].push_back(v);
        }

        // Find the starting node
        int start_node = pairs[0][0];
        for(auto &it: adjList)
        {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1)
            { 
                start_node = node;
                break;
            }
        }

        // Perform dfs
        stack<int> st;
        st.push(start_node);
        vector<int> euler_path;


        while(!st.empty())
        {
            int curr_node = st.top();

            if (!adjList[curr_node].empty())
            {
                int nbr = adjList[curr_node].back();
                adjList[curr_node].pop_back();
                st.push(nbr);
            }
            else
            {
                euler_path.push_back(curr_node);
                st.pop();
            }

        }


        reverse(euler_path.begin(), euler_path.end());

        for(int i=0; i<euler_path.size()-1; i++)
        {
            ans.push_back({euler_path[i], euler_path[i+1]});
        }

        return ans;

    }
};
