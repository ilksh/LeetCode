#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        int mx = -1;
        int n = number.size();

        for (int i = 0; i < n; ++i) {
            if (number[i] == digit) {
                string tempString = number.substr(0, i) + number.substr(i + 1, n); // delete the digit
                ans = max(ans, tempString); // string in decimal form is maximized
                } 
            } 
        return ans;   
    }
};