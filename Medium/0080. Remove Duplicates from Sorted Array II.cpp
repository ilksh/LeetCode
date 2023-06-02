#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MIN = -(1e4 + 1);
    const int MAX = 1e4 + 1;
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> hashMap;

        // intialize to zero
        for (int i = MIN; i < MAX; ++i) hashMap[i] = 0;
        vector<int> rst;
        for (auto num : nums) { // iterate all numbers in the vector
            // each unique element appears at most twice
            if (++hashMap[num] <= 2) rst.push_back(num);
        }
        nums.clear(); // remove all elements in the orginal vector
        for (auto e : rst) nums.push_back(e); // move all elements to original vector
        return rst.size(); // return the number of elements
    }
};