#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();    // number of elements
        vector<int> colored(n , 0); // vector with size of n. 0: uncolored; 1: color A; -1: color B
        queue<int> q; 

        for (int i = 0 ; i < n; ++i) {
            // skip already colored nodes > optimization
            if (colored[i] != 0) continue;

            colored[i] = 1; // color node i with color A
            q.push(i);
            while (!q.empty()) { // bfs
                auto cur = q.front(); q.pop();
                for (auto adj : graph[cur]) { // iterate all adjacent nodes
                    if (colored[adj] == 0) { // if the node is uncolored
                        colored[adj] -= colored[cur];
                        q.push(adj);
                    }
                    else if (colored[adj] == colored[cur]) {
                        // if already colored with the same color, it can't be bipartite!
                        return false;
                    }
                }
            }
        }
        return true;
    }
};