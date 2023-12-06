use std::collections::VecDeque;


impl Solution {
    const INF: i32 = 1_000_000_000;

    fn oob(n: usize, y: i32, x: i32) -> bool {
        y < 0 || y as usize >= n || x < 0 || x as usize >= n
    }

    pub fn shortest_path_binary_matrix(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        if grid[0][0] != 0 || grid[n - 1][n - 1] != 0 {
            return -1;
        }

        let dy = [0, 0, -1, 1, 1, -1, 1, -1];
        let dx = [-1, 1, 0, 0, 1, -1, -1, 1];

        let mut dp = vec![vec![Self::INF; n]; n];
        let mut q = VecDeque::new();

        q.push_back((0, 0));
        dp[0][0] = 1;

        while let Some((cur_y, cur_x)) = q.pop_front() {
            for dir in 0..8 {
                let ny = cur_y + dy[dir];
                let nx = cur_x + dx[dir];

                if Self::oob(n, ny, nx) || grid[ny as usize][nx as usize] == 1 {
                    continue;
                }

                let new_score = dp[cur_y as usize][cur_x as usize] + 1;
                if new_score < dp[ny as usize][nx as usize] {
                    dp[ny as usize][nx as usize] = new_score;
                    q.push_back((ny, nx));
                }
            }
        }

        if dp[n - 1][n - 1] == Self::INF {
            -1
        } else {
            dp[n - 1][n - 1]
        }
    }
}
