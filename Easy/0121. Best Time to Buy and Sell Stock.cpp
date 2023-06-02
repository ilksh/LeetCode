#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size(); // # of elements
        int minValue = 1e9; // greedy approach: max profit always comes from but in lowest price
        int maxProfit = -1; // greedy approach to calculate the maximum profit
        
        for (auto curPrice : prices) {
            // update the information of the minimum value
            if (curPrice < minValue) minValue = curPrice;
            int curProfit = curPrice - minValue;
            // update the information of the maximum profit
            if (curProfit > maxProfit) maxProfit = curProfit;
        }

        return maxProfit;
    }
};