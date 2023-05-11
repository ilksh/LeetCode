#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string rst = "";
        vector<pair<int, string>> storeIntRoman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                                    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
                                                    {4, "IV"}, {1, "I"}};
        
        for (auto e : storeIntRoman) {
            while (num >= e.first) {
                rst += e.second;
                num -= e.first;
            }
        }
        return rst;
    }
};