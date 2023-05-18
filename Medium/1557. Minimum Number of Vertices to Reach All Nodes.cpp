#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // measure of the number of incoming edges to that vertex within a directed graph
        int inDegree[n + 2];
        memset(inDegree, 0, sizeof(inDegree));
        for (auto e : edges) {
            int to = e[1]; // from = e[0]
            inDegree[to]++; // increase the indegree of current node
        }

        vector<int> ans;
        for (int i = 0; i < n ; ++i) { // iterate all nodes
            if (inDegree[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};