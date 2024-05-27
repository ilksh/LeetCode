#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> comb;
    int n;
    int k;

    void solve(int curNum) { // backtracking
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int num = curNum; num <= n; ++num) {
            comb.push_back(num);
            solve(num + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        solve(1);
        return res;        
    }
};
