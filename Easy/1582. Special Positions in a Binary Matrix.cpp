#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool rowCheck(vector<vector<int>>& mat, int curRow) {
        int colSize = mat[0].size();
        int cnt = 0;
        for (int col = 0; col < colSize; ++col) {
            if (mat[curRow][col] == 1) cnt++;
        }
        if (cnt == 1) return true;
        return false;
    }

    bool colCheck(vector<vector<int>>& mat, int curCol) {
        int rowSize = mat.size();
        int cnt = 0;
        for (int row = 0; row < rowSize; ++row) {
            if (mat[row][curCol] == 1) cnt++;
        }
        if (cnt == 1) return true;
        return false;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        int ans = 0;
        for (int r = 0; r < rowSize; ++r) {
            for (int c = 0; c < colSize; ++c)
                if (mat[r][c] == 1 && colCheck(mat, c) && rowCheck(mat, r)) {
                    cout << r << " " << c << "\n";
                    ans++;
                }
            
        }
        cout << ans << "\n";
        return ans;
    }
};