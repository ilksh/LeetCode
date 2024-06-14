#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<pii> window; 

        for (int i = 0; i < nums.size(); i++) {
            if (i > indexDiff) window.erase({nums[i - indexDiff - 1], i - indexDiff - 1});
            
            auto lowerBound = window.lower_bound({nums[i] - valueDiff, INT_MIN});
            
            if (lowerBound != window.end() && abs(lowerBound->first - nums[i]) <= valueDiff) {
                return true;
            }

            // Insert the current element into the set
            window.insert({nums[i], i});
        }

        return false;
    }
};

/*
Currently has Runtime Error 
-> What kind of optimiation needed?
-> Current O(n^2), where MAX_N = 1e5 -> OVERFLOW
-> How about
    -> Make pair {number, index}: O(n)
    -> Sort: O(nlogn)
    -> Search: O(logn)
-> Total < O(n^2)
-> Still

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= i + indexDiff && j < n; ++j) {
                int diff = abs(nums[i] - nums[j]);
                if (diff > valueDiff) continue;
                else return true;
            }
        }
        return false;
    }
};
*/