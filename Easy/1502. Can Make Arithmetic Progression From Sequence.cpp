#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size(); // number of elements
        if (n == 2) return true; // If there are only two numbers, we can make sequence
        sort(arr.begin(), arr.end()); // greedy approach : sorting the number
        int commonDiff = arr[1] - arr[0]; 
        
        for (int i = 2; i < n ; ++i) {
            int curDiff = arr[i] - arr[i -1];
            // through the comparison, we can know the the difference btw terms is maintained or not
            if (curDiff != commonDiff) return false;
        }
        return true;
    }
};