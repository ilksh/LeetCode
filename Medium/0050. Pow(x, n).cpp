#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    unordered_map<long long, double> dp; // use unordered_map for memoization

    double myPow(double x, long long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == -1) return 1.0 / x;

        // Avoid recalculation: memoization
        if (dp.find(n) != dp.end()) return dp[n]; 


        if (n % 2 == 0) {
            dp[n] = myPow(x, n / 2) * myPow(x, n / 2);
        }
        else {  
            if (n > 0) dp[n] =  myPow(x, n / 2 + 1) * myPow(x, n / 2);
            else  dp[n] = myPow(x, n / 2 - 1) * myPow(x, n / 2);
        }

        return dp[n];
    }
};