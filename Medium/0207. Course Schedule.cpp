#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAX_COURSE = 2 * 1e4 + 4;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[MAX_COURSE];
        int inDegree[MAX_COURSE];
        memset(inDegree, 0, sizeof(inDegree));

        for (auto vec : prerequisites) {
            int from = vec[1];
            int to = vec[0];
            adj[from].push_back(to);
            inDegree[to]++;
        }

        queue<int> q;

        for (int i = 0 ; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
    
        vector<int> finishedNode;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            for (auto e : adj[cur]) {
                inDegree[e]--;
                if (inDegree[e] == 0) finishedNode.push_back(e);
             }
        }
        int rstSize = finishedNode.size();
        bool rst = rstSize == numCourses ? true : false;
        return rst;
    }
};