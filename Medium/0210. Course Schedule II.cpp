#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAX_COURSE = 2 * 1e4 + 4;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> adj[MAX_COURSE];
        int inDegree[MAX_COURSE];
        memset(inDegree, 0, sizeof(inDegree));

        for (auto vec : prerequisites) {
            int to = vec[1];
            int from = vec[0];
            adj[from].push_back(to);
            inDegree[to]++;
        }
        
        queue<int> q; // topological sorting approach
        vector<int> finishedNode; // answer

        for (int i = 0 ; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                finishedNode.push_back(i);
            }
        }

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
        
            for (auto e : adj[cur]) {
                
                if (--inDegree[e] == 0) {
                    finishedNode.push_back(e);
                    q.push(e);
                }
             }
        }
        reverse(finishedNode.begin(), finishedNode.end());
        // if the sorting can be ended
        if (finishedNode.size() == numCourses) return finishedNode;
        
        vector<int> emp;
        return emp;
    }
};