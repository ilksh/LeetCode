#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAX = 1e5 + 5;
public:
    int findCenter(vector<vector<int>>& edges) {
        int edgeNum = edges.size();
        int connectedCnt[MAX];
        memset(connectedCnt, 0, sizeof(connectedCnt));

        for (auto vec : edges) {
            connectedCnt[vec[0]]++;
            connectedCnt[vec[1]]++;
        }

        for (int i = 0 ; i < MAX; ++i) {
            if (connectedCnt[i] == edgeNum) return i;
        }
        return 0;
    }
};