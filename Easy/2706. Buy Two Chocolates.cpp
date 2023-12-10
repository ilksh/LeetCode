class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // minimize the sum of the prices of the two chocolates you buy
        sort(prices.begin(), prices.end()); 
    
        // buy two cookies
        int sum = prices[0] + prices[1]; 

        // cannot buy two cookies
        if (sum > money) return money; 
        // buy two cookies -> return leftover
        return money - sum;

    }
};