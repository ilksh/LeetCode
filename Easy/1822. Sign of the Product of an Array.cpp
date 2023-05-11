#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int numNeg = 0; // number of negative numbers
        for (auto elem: nums) { // iterate all numbers
            if (elem < 0) numNeg++; // count the number of negative
            else if (elem == 0) return 0; // product with 0 is always 0
        }
        // there are odd number of negtive numbers > product is negative
        if (numNeg % 2) return -1;
        // there are even number of negative numbers > product is positive
        return 1;
    }
};