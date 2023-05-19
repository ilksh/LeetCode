#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // sort all words lexicographically
        vector<string> sortedStrs = strs;
        for (auto str : sortedStrs) sort(str.begin(), str.end());
        
        // key = sorted string, value = original string(s)
        unordered_map<string, vector<string>> hashMap;
        int n = strs.size(); // number of elements

        // matching word(s) formed by rearranging the letters of a different word or phrase
        for (int i = 0; i < n ; ++i) {
            auto sortedStr = sortedStrs[i];
            auto originalStr = strs[i];
            hashMap[sortedStr].push_back(originalStr);
        }

        vector<vector<string>> ans;
        for (auto hMap : hashMap) {
            ans.push_back(hMap.second);
        }

        return ans;
     }
};
