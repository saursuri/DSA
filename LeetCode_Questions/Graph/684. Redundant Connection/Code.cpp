/*
Problem Link: https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29
Time Complexity: O(Nα(N))
Space Complexity: O(N)
*/


class disjointSet{
    vector<int> parent;
    vector<int> size;
    public:
    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUltParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ultParU = findUltParent(u);
        int ultParV = findUltParent(v);

        if (ultParU == ultParV) return;

        if (size[ultParU] > size[ultParV])
        {
            parent[ultParV] = parent[ultParU];
            size[ultParU] += size[ultParV];
        }
        else
        {
            parent[ultParU] = parent[ultParV];
            size[ultParV] += size[ultParU]; 
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        disjointSet D(n);

        for (auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            // If no connection then join
            if (D.findUltParent(u) != D.findUltParent(v))
            {
                D.unionBySize(u,v);
            }
            else return edge;
        }

        return {-1,-1};
    }
};
