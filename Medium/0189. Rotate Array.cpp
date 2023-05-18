#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        int n = nums.size(); // number of elements in vector
        k %= n; // rotation has a cycle of n

        vector<int> temp;

        // original : {1 ~ n-k-1}{n-k ~ n}
        // after roation: {n-k ~ n}{1 ~ n-k-1}
        if (k <= n / 2) { // if k is smaller than the half
            // select last k numbers
            copy(nums.begin() + (n - k), nums.end(), back_inserter(temp));
            // erase the selected nunbers from the original vector
            nums.erase(nums.begin() + (n - k), nums.begin() + n);
            // insert original vector to the end of selected numbers
            temp.insert(temp.end(), nums.begin(), nums.end());
            nums = temp;
        }
        // original : {1 ~ k}{k +1 ~ n}
        // after roation: {k +1 ~ n}{1 ~ k}
        else { // if k is biger than the half
            // select fir k numbers
            copy(nums.begin(), nums.begin()+(n - k), back_inserter(temp));
            // erase the selected nunbers from the original vector
            nums.erase(nums.begin(), nums.begin() + (n - k));
            // insert selected vector to the end of original vector
            nums.insert(nums.end(), temp.begin(), temp.end());
        }
    }
};