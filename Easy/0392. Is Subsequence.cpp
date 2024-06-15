#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        int pOne = 0; // pointer one
        int pTwo = 0; // pointer two

        while (pOne < n && pTwo < m) {
            char curS = s[pOne];
            char curT = t[pTwo];

            if (curS == curT) pOne++;
            pTwo++;
        }

        if (pOne == n) return true;
        return false;
    }
};