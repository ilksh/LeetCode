#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int carry = 0, i = a.size()-1, j = b.size()-1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;
            int s = x + y + carry;
            sum = char(s % 2 + '0') + sum;
            carry = s / 2;
        }
        return sum;
    }
};
