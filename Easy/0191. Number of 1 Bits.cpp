#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n != 0) {
            num += (n %2);
            n >>= 1;
        }
        return num;
    }
};