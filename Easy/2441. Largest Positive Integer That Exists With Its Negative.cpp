#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;
        
        while(leftIdx < rightIdx) {
            int leftNum = nums[leftIdx];
            int rightNum = nums[rightIdx];

            if (leftNum == abs(rightNum) && rightNum < 0) return leftNum;
            if (leftNum >= abs(rightNum)) leftIdx++;
            else if (leftNum < abs(rightNum)) rightIdx--;
        }
        return -1;
    }
};