#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (auto elem : nums) {
            s.insert(elem);
        }

        int sz = s.size();
        nums.clear();
        for (auto elem : s) {
            nums.push_back(elem);
        }
        return sz;
    }
};