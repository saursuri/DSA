/*
Problem Link: https://leetcode.com/problems/count-sub-islands/description/
Time Complexity: O(No. of stones * alpha (m + n))
Space Complexity: O(m + n)
*/

class disjoint_set{
    public:
        vector<int> parent, size;

        disjoint_set(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);

            for (int i=0; i<=n; i++)
            {
                parent[i] = i;
            }
        }

        int find_ult_parent(int node)
        {
            if (parent[node] == node)
            {
                return node;
            }

            return parent[node] = find_ult_parent(parent[node]);
        }

        void union_by_size(int u, int v)
        {
            int ult_par_u = find_ult_parent(u);
            int ult_par_v = find_ult_parent(v);

            if (ult_par_u == ult_par_v) return;

            if (size[ult_par_u] >= size[ult_par_v])
            {
                parent[ult_par_v] = parent[ult_par_u];
                size[ult_par_u] += size[ult_par_v];
            }
            else
            {
                parent[ult_par_u] = parent[ult_par_v];
                size[ult_par_v] += size[ult_par_u];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = 0, n = 0;

        // Create the graph
        for (auto &it: stones){
            m = max(m, it[0]); // rows
            n = max(n, it[1]); // cols
        }

        unordered_set<int> valid_nodes;
        disjoint_set D(m+n+1);

        for (auto &it: stones)
        {
            int u = it[0];
            int v = m + it[1] + 1;

            // Create Union by size
            D.union_by_size(u,v);

            valid_nodes.insert(u);
            valid_nodes.insert(v);
        }

        int cnt=0;
        for (auto &it: valid_nodes)
        {
            if (D.parent[it] == it) cnt++;
        }

        return stones.size() - cnt;

    }
};
