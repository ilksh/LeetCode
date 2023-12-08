#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int combinations(int n, int k) {
        if (k > n - k) {
            k = n - k;
        }

        long long result = 1;
        for (int i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

public:
    int uniquePaths(int m, int n) {
        return combinations(m + n - 2, m - 1);
    }
};

