#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Hash map of integer and its frequency
        unordered_map<int, int> numFreq; 
        for (auto e : nums) numFreq[e]++;

        int mx = -1;
        int majorNum = -1;
        for (auto e : numFreq) {
            if (e.second > mx) {
                mx = e.second;
                majorNum = e.first;
            }
        }
        return majorNum;
    } 
};