#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // matrix is n by n matrix

        vector<vector<int>> rstMatrx; 
        for (int i = 0 ; i < n; ++i) {
            vector<int> temp;
            for (int j = n -1 ; j >= 0; --j) {
                temp.push_back(matrix[j][i]);
            }
            rstMatrx.push_back(temp);
        }
        matrix = rstMatrx;
    }
};