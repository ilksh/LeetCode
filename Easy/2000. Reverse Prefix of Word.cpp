#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> s;
        bool find = false;
        for (auto elem: word) {
            s.push(elem);
            if (elem == ch)  {
                find = true;
                break;
            }
        }
        if (!find) return word;
        int cnt = 0;
        while(!s.empty()) {
            auto cur = s.top(); s.pop();
            word[cnt++] = cur;
        }
        return word;
    }
};