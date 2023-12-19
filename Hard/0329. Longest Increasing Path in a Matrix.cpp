#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii; 
    int dy[4] = {0, 0, -1, 1}; // delta y
    int dx[4] = {-1, 1, 0, 0}; // delta x
    vector<vector<int>> dp; // Memoization for DFS

    // function which checks the Out Of Boundary
    bool OOB(int row, int col, int y, int x) {
        return y < 0 || y >= row || x < 0 || x >= col;
    }

    // DFS function with memoization
    int dfs(vector<vector<int>>& matrix, int y, int x) {
        if (dp[y][x] != -1) return dp[y][x];

        int maxRow = matrix.size();
        int maxCol = matrix[0].size();
        dp[y][x] = 1;

        for(int dir = 0; dir < 4; ++dir) {
            int nextRow = y + dy[dir]; 
            int nextCol = x + dx[dir];

            // do not traverse if it is out of boundary or not an increasing path
            if (OOB(maxRow, maxCol, nextRow, nextCol) || matrix[y][x] >= matrix[nextRow][nextCol]) continue;
      
            dp[y][x] = max(dp[y][x], 1 + dfs(matrix, nextRow, nextCol));
        }

        return dp[y][x];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int maxRow = matrix.size(); 
        int maxCol = matrix[0].size();
        // initialize dp array into -1
        dp.assign(maxRow, vector<int>(maxCol, -1));
        
        int mx = 0;

        for (int r = 0; r < maxRow; ++r) {
            for (int c = 0; c < maxCol; ++c) {
                mx = max(mx, dfs(matrix, r, c));
            }
        }
        
        return mx;
    }
};
