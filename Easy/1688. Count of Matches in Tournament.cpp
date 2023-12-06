#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while (n > 1) {
            int numMatch = n / 2;
            cout << numMatch << "\n";
            sum += numMatch;
            if (n % 2 == 1) {
              n /= 2;
              n++;
            }
            else{
              n /= 2;
            }
        }
        return sum;
    }
};