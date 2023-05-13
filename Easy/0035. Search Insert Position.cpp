#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = (int) nums.size();
        for (int i = 0; i < sz; ++i) {
            auto cur = nums[i];
            if (cur >= target) {
                return i;
            }
        }
        return sz;
    }
};