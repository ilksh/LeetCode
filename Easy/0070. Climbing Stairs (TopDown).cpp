#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int dp[46]; // max n = 45
    int solve(int n) {
        if (n <= 2) return n; // base case

        int& ret = dp[n]; // memoization
        if (ret != -1) return ret; // prevent re-calculation
        ret = solve(n - 1) + solve(n - 2); // there are two ways to reach nth stait
        return ret;
    }
    
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};