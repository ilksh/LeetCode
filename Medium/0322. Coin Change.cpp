#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int INF = 1e9; // Define a large value to represent infinity

public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        // Initialize the dp array with the value INF, as initially, we assume
        // that it's not possible to form any amount
        for(int i = 0; i <= amount; ++i) dp[i] = INF;

        // Base case: 0 coins are needed to make the amount 0
        dp[0] = 0;
        queue<int> q;
        q.push(0);

        // BFS-like approach to build up the solutions for each amount
        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for (auto coin : coins) {
                // Prevent integer overflow
                if (coin > amount - cur) continue;

                int next = cur + coin;
                int nextCost = dp[cur] + 1;

                // Update dp[next] if a better solution is found
                if (nextCost < dp[next]) {
                    dp[next] = nextCost;
                    q.push(next);
                }
            }
        }
        // If dp[amount] is still INF, it means the amount cannot be formed
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
