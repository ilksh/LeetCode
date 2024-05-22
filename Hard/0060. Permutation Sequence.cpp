#include<bits/stdc++.h>

using namespace std;

/*
 * Important
 * The first (n-1)! permutations will start with the smallest number,
 * The next (n-1)! permutations will start with the second smallest number, and so on.
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        string rst = "";

        int factorial = 1; // factorial value will be used to specify group

        for (int i = 0; i < n ; ++i) {
            numbers.push_back(i + 1); // make (1, 2, ... , n- 1, n)
            factorial *= (i + 1);  // make n!
        }

        k--; 

        // find the group 
        for (int i = 0; i < n ; ++i) {
            factorial /= (n - i); 
            int groupIdx = k / factorial; // find the index of the group
            rst += to_string(numbers[groupIdx]);
            numbers.erase(numbers.begin() + groupIdx); // update the new 
            k %= factorial;
        }

        return rst;

    }
};