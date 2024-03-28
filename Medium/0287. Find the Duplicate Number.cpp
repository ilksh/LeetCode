#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAX_N = 1e5 + 1;
public:
    int findDuplicate(vector<int>& nums) {
        bool used[MAX_N];
        memset(used, false, sizeof(used));
        int ans = -1;
        for (auto num: nums) {
            if (used[num]) {
                ans = num;
                break;
            }
            used[num] = true;
        }
        return ans;
    }
};