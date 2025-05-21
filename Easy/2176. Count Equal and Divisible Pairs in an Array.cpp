#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        set<int> s;

        for (auto num: nums) {
            s.insert(num);
        }

        int cnt = 0;
        for (auto elem: s) {
            cout << elem << " ";
            if (elem % k == 0) cnt++;
        }
        return cnt;
    }
};