#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Hash map of integer and its frequency
        unordered_map<int, int> numFreq; 
        for (auto e : nums) numFreq[e]++;
        int ans = 0;
        for (auto e: numFreq) {
            if (e.second == 1) {
                ans = e.first;
                break;
            }
        }
        return ans;
    }
};