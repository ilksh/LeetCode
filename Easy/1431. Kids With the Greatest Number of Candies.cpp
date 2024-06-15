#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = -1;
        for (auto candy : candies) mx = max(mx, candy);

        vector<bool> ans;

        for (auto candy : candies) {
            int diff = mx - candy;
            bool flag = diff <= extraCandies ? 1 : 0;
            ans.push_back(flag);
        }

        return ans;
    }
};