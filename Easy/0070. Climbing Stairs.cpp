#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n +2];
        memset(dp, 0, sizeof(dp)); // initialize
        dp[1] = 1; // base case
        dp[2] = 2; // base case

        for (int i = 3; i < n + 1; ++i) { // caculate the number of ways to reach nth stair
            int moveByOne = dp[i -1];
            int moveByTwo = dp[i -2];
            dp[i] =moveByOne + moveByTwo;
        }
        return dp[n];
    }
};