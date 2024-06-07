#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<string> rst;

        for (char c = 'a'; c <= 'z'; ++c) {
            int mn = 1e9;

            for (auto word: words) {
                int cnt = 0;
                for (auto curChar: word) {
                    if (curChar == c) cnt++;
                }
                mn = min(mn, cnt);
                if (mn == 0) break; // no need to check
            }
            for (int i = 0; i < mn; ++i) {
                rst.push_back(string(1, c));
            }
        }

        return rst;
    }
};
