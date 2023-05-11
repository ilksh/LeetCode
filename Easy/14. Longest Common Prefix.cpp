#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = ""; 
        // minimum lenght of string
        // intialize to extreme value (greedy approach)
        int minLenght = 2 >> 20; 
    
        for (auto s : v) { // find the minimum length
            int curLength = s.length();
            if (curLength < minLenght) minLenght = curLength;
        }

        // Sort the input vector lexicographically
        sort(v.begin(), v.end());
        string frontStr = v[0];
        string rearStr = v[v.size() - 1]; 

        // Greedy approach assumes that frontStr and rearStr will be different in the sorintg vector
        for (int i = 0 ; i < minLenght; ++i) {
            if (frontStr[i] != rearStr[i]) break;
            ans += frontStr[i];
        }
        return ans;
    }
};