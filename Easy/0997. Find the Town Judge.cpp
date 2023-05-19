#include<bits/stdc++.h>

using namespace std;

/*
 * 1. Intuition
 * To find the judge in the town, we need to identify a person who is trusted by everyone else and does not trust anyone. 
 * To determine this, we can calculate the in-degree and out-degree of each person. 
 * The person with an in-degree of n - 1 (where n is the total number of people) 
   and an out-degree of 0 would be the potential judge.

 * 2. Approach
 * The approach involves the following steps:
 * a) Create two arrays: inDegree and outDegree, both initialized with 0s. 
 *    The size of these arrays is n + 1 to accommodate indices from 1 to n.
 * b) Iterate over the trust vector and update the in-degree and out-degree arrays accordingly.
 * c) Finally, iterate over the arrays and check for a person who satisfies the conditions of
 *    being trusted by everyone else (in-degree of n - 1) and not trusting anyone (out-degree of 0).
 *    Return the index of such a person if found; otherwise, return -1.
 
 * 3. Complexity 
 * Time complexity: O(E), where E is the number of trust relationships given in the trust vector.
 * Space complexity: O(N), where N is the total number of people in the town.
 */

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