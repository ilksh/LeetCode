#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // merged array should be in the nums1
        // thus, erase all elements whose index is bigger than m
        nums1.erase(nums1.begin() + m, nums1.end());

        // first n elements denote the elements that should be merge from nums2
        for (int i = 0 ; i < n; ++i) nums1.push_back(nums2[i]);
        
        sort(nums1.begin(), nums1.end());
    }
};