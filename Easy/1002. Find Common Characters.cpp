#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isInWord(string word, char alphabet) {
        for (auto e : word) {
            if (e == alphabet) return true;
        }
        return false;
    }

public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        int freq[27];
        memset(freq, 0, sizeof(freq));

        for (auto word: words) {
            for (auto curChar: word) {
                int num = curChar - 'a';
                freq[num]++;
            }
        }
        for (int i = 0; i < 27; ++i) cout << freq[i] << " ";
        vector<string> ans;

        for (int i = 0; i < 27; ++i) {
            if (freq[i] >= n) {
                char curChar = i + 'a';
                while(freq[i] > 0) {
                    string curStr = "";
                    curStr += curChar;
                    ans.push_back(curStr);
                    freq[i] /= n;
                }
            }
        }
        return ans;
    }
};