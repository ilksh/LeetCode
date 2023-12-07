#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size(); // length of string
        int dp[n];   // number of substrings with same number for each position
        int maxLenSubString[10]; // maximum Length substring for each digit
        
        // initialize
        memset(dp, 0, sizeof(dp));
        memset(maxLenSubString, 0, sizeof(maxLenSubString));

        int curNum = num[0] - '0';
        dp[0] = 1;

        for (int i =  1 ; i < n ; ++i) {
            int curNum = num[i] - '0';  // current number
            int prev = num[i - 1] - '0'; // previous number

            // if substring detected, increase the number of substring
            if (curNum == prev)  dp[i]= dp[i - 1] + 1;
            
            // start of substring
            else  dp[i] = 1;
            
            // update the info of max length of substring
            maxLenSubString[curNum] = max(maxLenSubString[curNum], dp[i]);
        }
        
        // good integer
        int goodInt = -1;

        for (int i = 0; i < 10 ;++i) {
            //  find maximum good integer
            if (maxLenSubString[i] >= 3) goodInt = max(goodInt, i);
        }

        string ans = "";
        // we could not find a good integer
        if (goodInt == -1) return ans;
        char charNum = goodInt + '0';
        
        for (int rep = 0; rep < 3; ++rep) ans += charNum;
        return ans;
    }
};

