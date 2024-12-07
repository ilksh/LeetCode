#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp; 

    int solve(int row, int col, vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Out-of-bounds check
        if (col < 0 || col >= n) return INT_MAX;

        // Base case
        if (row == 0) return matrix[row][col];

        int& ret = dp[row][col];
        if (ret != INT_MAX) return ret;

        int upLeft = solve(row - 1, col - 1, matrix); // Diagonally left
        int up = solve(row - 1, col, matrix);         // Directly above
        int upRight = solve(row - 1, col + 1, matrix); // Diagonally right

        return ret = matrix[row][col] + min({upLeft, up, upRight});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        dp = vector<vector<int>>(n, vector<int>(n, INT_MAX)); 
        int result = INT_MAX;

        for (int col = 0; col < n; ++col) {
            result = min(result, solve(n - 1, col, matrix));
        }

        return result;
    }
};