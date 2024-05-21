#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 2 << 4;

typedef pair<int, int> pii;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int curRow, int curCol, int maxRow, int maxCol) {
    return curRow < 0 || curRow >= maxRow || curCol < 0 || curCol >= maxCol;
}

int maxBFS(vector<vector<int>> grid, pii startPosition) {
    auto startRow = startPosition.first;
    auto startCol = startPosition.second;

    if (grid[startRow][startCol] == 0) return -1;
    
    int maxRow = grid.size();
    int maxCol = grid[0].size();

    queue<pii> q;

    int dp[MAX_N][MAX_N];
    bool visited[MAX_N][MAX_N];

    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));
    
    q.push(startPosition);
    visited[startRow][startCol] = true;
    dp[startRow][startCol] = grid[startRow][startCol];
    int mx = dp[startRow][startCol];

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int curRow = cur.first;
        int curCol = cur.second;

        for (int dir = 0; dir < 4; ++dir) {
            int nextRow = curRow + dy[dir];
            int nextCol = curCol + dx[dir];

            if (OOB(nextRow, nextCol, maxRow, maxCol) || visited[nextRow][nextCol] 
                || grid[nextRow][nextCol] == 0) continue;

            int nextCost = dp[curRow][curCol] + grid[nextRow][nextCol];

            if (nextCost > dp[nextRow][nextCol])  {
                visited[nextRow][nextCol] = true;
                dp[nextRow][nextCol] = nextCost;
                mx = mx < dp[nextRow][nextCol] ? dp[nextRow][nextCol] : mx;
                q.push({nextRow, nextCol});
            }
        }
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> grid;

    int m, n;
    cin >> m >> n;

    grid = {{1,0,7,0,0,0},
            {2,0,6,0,1,0},
            {3,5,6,7,4,2},
            {4,3,1,0,2,0}, 
            {3,0,5,0,20,0}};

    int mx = -1;
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            int rst = maxBFS(grid, {row, col});
            cout << rst << " ";
            mx = mx < rst ? rst : mx;
        }   
        cout << "\n";
    }
    cout << "Result: " << mx << "\n ";
    return 0;
}