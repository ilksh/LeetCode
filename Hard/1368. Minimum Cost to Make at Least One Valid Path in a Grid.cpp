#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            int row = node.first;
            int col = node.second;

            if (row == m - 1 && col == n - 1) {
                return cost;
            }

            for (int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newCost = cost + checkCost(dx[i], dy[i], grid[row][col]);

                    if (newCost < dist[x][y]) {
                        dist[x][y] = newCost;
                        pq.push({newCost, {x, y}});
                    }
                }
            }
        }

        return -1;
    }

private:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int checkCost(int dx, int dy, int val) {
        if (dx == 0 && dy == 1 && val == 1) {
            return 0;
        }
        
        if (dx == 0 && dy == -1 && val == 2) {
            return 0;
        }
        if (dx == 1 && dy == 0 && val == 3) {
            return 0;
        }
        if (dx == -1 && dy == 0 && val == 4) {
            return 0;
        }
        return 1;
    }
};
