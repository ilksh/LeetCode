class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;

        for (int i = 1; i <n; ++i) {
            int prevPrice = prices[i - 1];
            int curPrice = prices[i];
            auto diff = curPrice - prevPrice;
            
            if (diff > 0)  dp[i] = dp[i - 1] + diff;
            
            else dp[i] = dp[i - 1];
        }
        
        return dp[n - 1];
    }
};