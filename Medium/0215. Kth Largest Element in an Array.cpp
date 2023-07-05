#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii; // {minimum, maximum}
public:
    pii findMinMax(vector<int>& nums) {
        pii minMax = {(int) 1e9, -1}; // greedy approach 

        for (auto num : nums) {
            // update min and max
            if (num < minMax.first) minMax.first = num;
            if (num > minMax.second) minMax.second = num;
        }
        return minMax;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // find min and max using library function
        // int left = *std::min_element(nums.begin(), nums.end());
        // int right = *std::max_element(nums.begin(), nums.end());

        int left = findMinMax(nums).first;
        int right = findMinMax(nums).second;

        while (left < right) { // binary search
             int mid = left + (right - left) / 2; // middle point
            int cnt = 0; // number of elements bigger than mid value

            for (auto num : nums) { // iterate all numbers in vector
                if (num > mid) cnt++; // count the number
            }

            // if cnt is equal or bigger than k, change left bound
            if (cnt >= k) left = mid + 1;
            // else change right bound
            else right = mid;
        }

    return left;
    }
};