/*
Problem Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27
Time Complexity: O(NLogN + MLogN)
Space Complexity: O(N)
*/

#define Pair pair<int, int>

class Solution {
private:
    vector<long long> findMin(vector<pair<int, int>> adjList[], int src)
    {
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        
        // Push source to pq
        pq.push({0, src});

        vector<long long> distance(26, 10e9);
        distance[src] = 0;

        while(!pq.empty())
        {
            auto topElem = pq.top();
            int node = topElem.second;
            int nodeCost = topElem.first;
            pq.pop();

            // Visit neighbors
            for(auto neighbor: adjList[node])
            {
                int adjNode = neighbor.first;
                int adjNodeCost = neighbor.second;

                if (nodeCost + adjNodeCost < distance[adjNode])
                {
                    distance[adjNode] = nodeCost + adjNodeCost;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        return distance;
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        // Create Graph
        vector<pair<int, int>> adjList[26];
        
        int m = original.size();
        for(int i=0; i<m; i++)
        {
            adjList[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        // Find the min distance from source to dest for every node
        vector<long long> hash[26];
        for(int i=0; i<26; i++)
        {
            hash[i] = findMin(adjList, i);
        }

        long long minCost = 0;
        long long travelCost;
        int n = source.length();
        for(int i=0; i<n; i++)
        {
            travelCost = hash[source[i]-'a'][target[i]-'a'];
            if (travelCost == 10e9) return -1;

            minCost += travelCost;
        }

        return minCost;
    }
};
