#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    typedef vector<vector<int>> vvi;

    int calcInRow(vector<vector<int>>& grid, int target, int curRow) {
        int colSize = grid[0].size();
        int cnt = 0; // number of target in the same row
        for (int c = 0; c < colSize; ++c) { // iterate all positions with same row
            if (grid[curRow][c] == target) cnt++;
        }
        return cnt;
    }
    int calcInCol(vector<vector<int>>& grid, int target, int curCol) {
        int rowSize = grid.size();
        int cnt = 0; // number of target in the same column
        for (int r = 0; r < rowSize; ++r) { // iterate all positions with same column
            if (grid[r][curCol] == target) cnt++;
        }
        return cnt;
    }
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vvi ans;

        int rowSize = grid.size(); 
        int colSize = grid[0].size();

        int dpRow[rowSize]; // number of one in the row - number of zero in the row
        int dpCol[colSize]; // number of one in the col - number of zero in the col

        memset(dpRow, -1, sizeof(dpRow)); // initialize
        memset(dpCol, -1, sizeof(dpCol)); // initialize

        for (int r = 0; r < rowSize; ++r) { 
            vector<int> tempVec;
            for (int c = 0; c < colSize; ++c) {
                int rowCalc = 0;

                // found that the same row has same "number of one in the row - number of zero in the row"
                if (dpRow[r] == -1)  { // prevent the recalculation
                    dpRow[r] = calcInRow(grid, 1, r) - calcInRow(grid, 0, r);
                }
                int rowVal = dpRow[r];

                // found that the same col has same "number of one in the col - number of zero in the col"
                if (dpCol[c] == -1) { // prevent the recalculation
                    dpCol[c] =  calcInCol(grid, 1, c) - calcInCol(grid, 0, c);
                }
                int colVal = dpCol[c];

                int diff = rowVal + colVal;
                tempVec.push_back(diff);
            }
            ans.push_back(tempVec);
        }
        return ans;
    }
};

