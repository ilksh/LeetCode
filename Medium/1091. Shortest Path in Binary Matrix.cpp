#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
    typedef pair<int, int> pii; // {y-coordinate, x-coordinate}
    int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1}; // delta y
    int dx[8] = {-1, 1, 0, 0, 1, -1, -1, 1}; // delta x
    const int INF = (int) 1e9;

    // function which checks the Out Of Boundary
    bool OOB(int n, int y, int x) { 
        return y < 0 || y >= n || x < 0 || x >= n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // n by n matrix
        // If there is no entrance or exit (inclusive or) > impossible to finish traverse (edge case)
        if (grid[0][0] + grid[n -1][n -1] != 0) return -1;

        // number of visited cells of this path {y-coord, x-coord}
        int dp[n + 1][n + 1];  

        // initialize dp array to INF: greedy approach
        for (int row = 0 ; row < n ; ++row) {
            for (int col = 0 ; col < n; ++col) 
                dp[row][col] = INF;
        }

        queue<pii> q;   // BFS Traverse 
        q.push({0, 0}); // Start (top-left cell)
        dp[0][0] = 1;

        while (!q.empty()) { // BFS 
            auto cur = q.front(); q.pop(); 
            int curY = cur.first;  // current y coordinate
            int curX = cur.second; // current x coordinate
            for (int dir = 0 ; dir < 8 ; ++dir) { // path are 8-directionally connected
                int ny = curY + dy[dir]; // new y coordinate
                int nx = curX + dx[dir]; // new x coordinate
                
                // If the new coordinate is out of boundary or non visited cell, don't proceed travers
                if (OOB(n, ny, nx) || grid[ny][nx] == 1) continue;

                // new number of visited cells of new path
                int newScore = dp[curY][curX] + 1;
                // If new path is shorter than current path
                if (newScore < dp[ny][nx]) {
                    dp[ny][nx] = newScore; 
                    q.push({ny, nx}); 
                }
            }
        }
       // "dp[n-1][n-1] = INF" means that the info of dp has not been updated,
       // which means that it has not reached the bottom-right cell 
        if (dp[n - 1][n -1] == INF) return -1;
        
        else return dp[n -1][n -1]; 
    }
};