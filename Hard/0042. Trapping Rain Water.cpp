#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int INF = 1e9;
public:
    int trap(vector<int>& nums) {
        int leftIdx{0}, rightIdx{0}, sum{0}, leftMax{-INF}, rightMax{-INF};
        rightIdx = nums.size() - 1;
        while (leftIdx < rightIdx) {
            leftMax = max(leftMax, nums[leftIdx]);
            rightMax = max(rightMax, nums[rightIdx]);
            auto add = 0;
            cout << leftIdx << " " << rightIdx << " ";
            if (leftMax < rightMax) add = (leftMax - nums[leftIdx++]);
            else add = (rightMax - nums[rightIdx--]);
            cout  << add << "\n";
            sum += add;
        }
        return sum;
    }
};
