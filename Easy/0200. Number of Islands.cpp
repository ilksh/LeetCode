#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> pii; 
    int dy[4] = {0, 0, -1, 1}; // delta y
    int dx[4] = {-1, 1, 0, 0}; // delta x
    // function which checks the Out Of Boundary
    bool OOB(int row, int col, int y, int x) {
        return y < 0 || y >= row || x < 0 || x >= col;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row =  grid.size();    // number of row
        int col = grid[0].size();  // number of col

        bool visited[row + 1][col +1];       // check current coordinate is visited or not
        memset(visited, 0, sizeof(visited)); // initialize to false

        int cnt  = 0; // number of island
        queue<pii> q; // bfs

        for (int r = 0; r < row ; ++r) { // iterate all rows
            for (int c = 0 ; c < col; ++c) { // interate all columns
                // Exploration Conditions: Never visited and the present must be land
                if (grid[r][c] == '1' && !visited[r][c]) {  
                    q.push({r, c});  
                    visited[r][c] = true;
                    cnt++;
                    while (!q.empty()) { // explores all the adjacent vertices
                        auto cur = q.front(); q.pop(); 
                        for (int dir = 0; dir < 4; ++dir) { // move to four directions
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            // new coordinate is out of boundary or already visited
                             if(OOB(row, col, ny, nx) || visited[ny][nx]) continue;
                    
                             if (grid[ny][nx] == '1') q.push({ny, nx});
                             visited[ny][nx] = true;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};