#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> dp;

    int solve(int i, vector<int>& cost) {
        if (i < 0) return 0; 
        if (i == 0 || i == 1) return 0; // Base case: 

        int& ret = dp[i];
        if (ret != -1) return ret;

        return ret = min(solve(i - 1, cost) + cost[i - 1], solve(i - 2, cost) + cost[i - 2]);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n + 1, -1); 
        return solve(n, cost);
    }
};