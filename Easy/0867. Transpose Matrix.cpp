#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> transposedMtrx;
        for (int c = 0; c < col; ++ c) {
            vector<int> newRow;

            for (int r = 0; r < row; ++r) 
                newRow.push_back( matrix[r][c]);
            transposedMtrx.push_back(newRow);
            
        }
        return transposedMtrx;
    }
};