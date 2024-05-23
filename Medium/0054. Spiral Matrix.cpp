#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;  // (row, col)
const int MAX = 2 << 3 + 3;  

int maxRow = 0;
int maxCol = 0;

class Solution {
private:
    pii rushRight(vector<vector<int>>& matrix, bool(&visited)[MAX][MAX], pii startPos, vector<int>* ans) {
        int curRow = startPos.first;
        int curCol = startPos.second;
        
        if (curCol + 1 >= maxCol || visited[curRow][curCol + 1]) return {-1, -1};

        while (curCol + 1 < maxCol && !visited[curRow][curCol + 1]) {
            visited[curRow][++curCol] = true;
            ans->push_back(matrix[curRow][curCol]);
        }

        return {curRow, curCol};
    }

    pii rushDown(vector<vector<int>>& matrix, bool(&visited)[MAX][MAX], pii startPos, vector<int>* ans) {
        int curRow = startPos.first;
        int curCol = startPos.second;

        if (curRow + 1 >= maxRow || visited[curRow + 1][curCol]) return {-1, -1};
        
        while (curRow + 1 < maxRow && !visited[curRow + 1][curCol]) {
            visited[++curRow][curCol] = true;
            ans->push_back(matrix[curRow][curCol]);
        }

        return {curRow, curCol};
    }

    pii rushLeft(vector<vector<int>>& matrix, bool(&visited)[MAX][MAX], pii startPos, vector<int>* ans) {
        int curRow = startPos.first;
        int curCol = startPos.second;
        if (curCol - 1 < 0 || visited[curRow][curCol - 1]) return {-1, -1};
  
        while (curCol - 1 >= 0 && !visited[curRow][curCol - 1]) {
            visited[curRow][--curCol] = true;
            ans->push_back(matrix[curRow][curCol]);
        }

        return {curRow, curCol};
    }

    pii rushUp(vector<vector<int>>& matrix, bool(&visited)[MAX][MAX], pii startPos, vector<int>* ans) {
        int curRow = startPos.first;
        int curCol = startPos.second;

        if (curRow - 1 < 0 || visited[curRow - 1][curCol]) return {-1, -1};

        while (curRow - 1 >= 0 && !visited[curRow - 1][curCol]) {
            visited[--curRow][curCol] = true;
            ans->push_back(matrix[curRow][curCol]);
        }

        return {curRow, curCol};
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        maxRow = matrix.size();
        maxCol = matrix[0].size();
        bool visited[MAX][MAX];
        memset(visited, false, sizeof(visited));

        pii startPos = {0, -1};  
        int turn = 0;

        do {
            if (turn == 0) startPos = rushRight(matrix, visited, startPos, &ans);

            else if (turn == 1) startPos = rushDown(matrix, visited, startPos, &ans);

            else if (turn == 2) startPos = rushLeft(matrix, visited, startPos, &ans);

            else if (turn == 3) startPos = rushUp(matrix, visited, startPos, &ans);
            
            turn = (turn + 1) % 4;  // Cycle through 0 to 3
        } while (startPos.first != -1 && startPos.second != -1);

        return ans;
    }
};
