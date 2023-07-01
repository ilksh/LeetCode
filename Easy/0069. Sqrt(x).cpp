#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
    unordered_map<int, int> memo;
public:
    int mySqrtHelper(int x) {
        // base case
        if (x < 2) return x;

        // checks if the element with key x exists in the memo map
        if (memo.find(x) != memo.end()) return memo[x];

        int start = 1;
        int end = x;
        int ans;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (mid * mid <= x) {
                start = mid + 1; // incrase the mid
                ans = mid;
            }
            else {
                // decrease the end
                end = mid - 1; 
            }
        }

        memo[x] = ans;
        return ans;
    }

    int mySqrt(int x) {
        return mySqrtHelper(x);
    }
};