#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n + 1]; // adjacent matrix
        for (auto e : edges) {
            int node1 = e[0];
            int node2 = e[1];
            adj[node1].push_back(node2); // undirected graph
            adj[node2].push_back(node1); // undirected graph
        }
         
        bool visited[n + 1]; // visited array to check the node is visited or not
        memset(visited, false, sizeof(visited)); // initialize to false

        queue<int> q; // bfs approach
        q.push(source); // source is always a start
        visited[source] = true;

        while (!q.empty()) { // iterate there are no elements in queue
            auto cur = q.front(); q.pop();  // The front of q means the node that is currently being searched. 
            for (auto e : adj[cur] ) {      // iterate all adjacent nodes
                if (!visited[e]) {          // only traverse non visited node (optimization)
                    visited[e] = true;      // update the information
                    q.push(e);              // add candidates
                }
            }
        }
        // determine whether we can visit from source to destination using bfs method
        bool rst = visited[destination] ? true : false;
        return rst;
    }
};