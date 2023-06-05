#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // number of nodes
        vector<int> adj[n + 1]; // adjacent matrix
        bool visited[n + 1]; // boolean array in order to avoid revisit 
        memset(visited, false, sizeof(visited)); // initialize to false

        for (int i = 0; i < n ; ++i) { 
            vector<int> curVec = isConnected[i];
            for (int j = 0; j < n; ++j) {
                // Checking adjacency (except for node itself)
                if (i != j && curVec[j] == 1) adj[i + 1].push_back(j + 1);
            }
        }
        // BFS technique that uses queues to explore all nodes adjacent to the current node
        queue<int> q; 
        int numOfProvince = 0; // number of province
        for (int i = 1 ; i < n + 1; ++i) {
            if (visited[i]) continue; // prevent revisit
            visited[i] = true; 
            q.push(i); // start exploring
            while (!q.empty()) { // explore all adjacent nodes to node i
                auto cur = q.front(); q.pop();
                for (auto e : adj[cur]) {
                    if (!visited[e]) {
                        visited[e] = true;
                        q.push(e);
                    }
                }
            }
            numOfProvince++;
        }
        return numOfProvince;
    }
};