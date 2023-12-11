#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    typedef vector<vector<int>> vvi;
public:
    vector<vector<int>> generate(int numRows) {
        vvi ans;
        if (numRows == 0) return ans ;
        ans.push_back({1});
        for(int i = 1; i < numRows; ++i) {
            vector<int> prevRow = ans[i - 1];
            vector<int> curRow = {1};
       
            for (int j = 1; j < prevRow.size(); ++j) {
                auto curVal = prevRow[j - 1] + prevRow[j];
                curRow.push_back(curVal);
            }
            curRow.push_back(1);
            ans.push_back(curRow);
        } 
        return ans;
    }
    
};

