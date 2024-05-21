#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[40];

    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        if (dp[n] != -1) return dp[n];
        
        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};
