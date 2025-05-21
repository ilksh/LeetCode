#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[5001][301]; 
    int solve(int n, int index, vector<int>& coins) {
        if (n < 0) return 0; 
        if (n == 0) return 1; 

        if (index >= coins.size()) return 0;

        int& ret = dp[n][index];
        if (ret != -1) return ret; 

        ret = solve(n - coins[index], index, coins) + solve(n, index + 1, coins);
        return ret;
    }

public:
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp)); 
        return solve(amount, 0, coins); 
    }
};
