#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adj[n + 1];
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n ; ++i) {
            vector<int> curVec = isConnected[i];
            for (int j = 0; j < n; ++j) {
                if (i != j && curVec[j] == 1) adj[i + 1].push_back(j + 1);
            }
        }
        queue<int> q;
        int numOfProvince = 0;
        for (int i = 1 ; i < n + 1; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
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