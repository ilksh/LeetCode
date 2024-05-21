#include<bits/stdc++.h>
using namespace std;

const int MAX = 2 << 5;

class Solution {
private:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    bool OOB(int curRow, int curCol, int maxRow, int maxCol) {
        return curRow < 0 || curRow >= maxRow || curCol < 0 || curCol >= maxCol;
    }

    int maxDFS(vector<vector<int>>& grid, int row, int col, bool visited[MAX][MAX]) {
        int maxGold = 0;
        visited[row][col] = true;
        int maxRow = grid.size();
        int maxCol = grid[0].size();

        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + dy[dir];
            int newCol = col + dx[dir];
            if (OOB(newRow, newCol, maxRow, maxCol) || visited[newRow][newCol]
                || grid[newRow][newCol] == 0) continue;
            
            maxGold = max(maxGold, maxDFS(grid, newRow, newCol, visited));
        }
        
        visited[row][col] = false; 
        return grid[row][col] + maxGold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = -1;
        bool visited[MAX][MAX];
        memset(visited, false, sizeof(visited));

        int maxRow = grid.size();
        int maxCol = grid[0].size();

        for (int row = 0; row < maxRow; ++row) {
            for (int col = 0; col < maxCol; ++col) {
                if (grid[row][col] > 0) maxGold = max(maxGold, maxDFS(grid, row, col, visited));
            }
        }
        return maxGold;
    }
};