#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp = {};
        int n = arr.size();
        int idx = 0;
        while (temp.size() < arr.size()) {
            int cur = arr[idx++];
            if (cur == 0 && idx < arr.size()) temp.push_back(0);
            temp.push_back(cur);
        }
        arr.clear();
        for (int i = 0; i < n; ++i) arr.push_back(temp[i]);

    }
};