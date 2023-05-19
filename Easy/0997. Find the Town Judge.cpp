#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n < 2) return n; // base case
        int inDegree[n +1], outDegree[n +1];
        memset(inDegree, 0, sizeof(inDegree));   // initialize inDegree to 0
        memset(outDegree, 0, sizeof(outDegree)); // initialize outDegree to 0

        for (auto vec : trust) { // iterate all vector(s) in trust
            // node vec[0] trusts node vec[1]
            // vec[0] -> vec[1], thus arrow points from vec[0] to vec[1]
            int curFrom = vec[0];  
            int curTo = vec[1];
            inDegree[curTo]++;     // inDegree means number of people who trust current node
            outDegree[curFrom]++;  // outDegree means number of people current node trusts
        }

        for (int i = 0 ; i < n + 1; ++i) {
            // The town judge trusts nobody = ourDegree is 0
            // Everybody trusts the town judge = inDegree is n -1.
            if (inDegree[i] == n -1 && outDegree[i] == 0) return i;
        }
        return -1;
    }
};