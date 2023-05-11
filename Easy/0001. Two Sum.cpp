#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> rst;
        int sz = nums.size();

        for (int i=0; i < sz; ++i)
            umap.insert({nums[i],i});
        
        for (int i=0; i < sz; ++i) {
            int cur = target - nums[i];
            if (umap.find(cur) != umap.end()) {
                if (umap[cur] != i) { // find the target
                rst.push_back(i);
                rst.push_back(umap[cur]);
                return rst;
                }
            }
        }
        return rst;
    }
};