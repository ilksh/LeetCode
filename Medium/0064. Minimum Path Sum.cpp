#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    typedef pair <int, int> pii;
    const int INF = 1e9;

    int dy[4] = {1, 0}; //  You can only move either down or right at any point in time.
    int dx[4] = {0, 1};

    bool OOB(int row, int col, int y, int x) { // check that the current position is out of boundary
        return y < 0 || y >= row || x < 0 || x >= col;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(); // row size 
        int col = grid[0].size(); // column size
        int dp[row + 1][col + 1]; // cost to get into the position
        
        for (int i = 0; i < row; ++i) { // initialize the dp array
            for(int j = 0 ; j < col; ++j) dp[i][j] = INF;
        }
        
        queue<pii> q;

        q.push({0, 0});
        dp[0][0] = grid[0][0]; 

        while (!q.empty()) { // bfs approach
            auto cur = q.front(); q.pop();

            for (int dir = 0; dir < 2; ++dir) { // move the positon
                int nextRow = cur.first + dy[dir]; 
                int nextCol = cur.second + dx[dir];
                
                // do not traverse when it is out of boundary
                if (OOB(row, col, nextRow, nextCol)) continue; 

                int nextCost = dp[cur.first][cur.second] + grid[nextRow][nextCol];
                
                if (dp[nextRow][nextCol] > nextCost) {
                     dp[nextRow][nextCol] = nextCost;
                     q.push({nextRow, nextCol});
                }
               
            }
        }
        return dp[row - 1][col - 1];
    }
};