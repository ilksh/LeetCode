#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cnt = 0; 
        int need = 0; 
        
        for (int i = 0; i < nums.size(); ++i) {
            cnt += max(0, need - nums[i]);
            need = max(need, nums[i]) + 1;
        }
        
        return cnt;
    }
};
