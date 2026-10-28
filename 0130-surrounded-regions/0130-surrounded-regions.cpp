class Solution {
public:
      void dfs(int i, int j, int n, int m, vector<vector<char>>& board,vector<vector<bool>>& vis, bool& touch,vector<pair<int, int>>& cells) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;
        if (board[i][j] != 'O' || vis[i][j])
            return;
        vis[i][j] = true;
        cells.push_back({i, j});
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            touch = true;
        }
        dfs(i + 1, j, n, m, board, vis, touch, cells);
        dfs(i - 1, j, n, m, board, vis, touch, cells);
        dfs(i, j + 1, n, m, board, vis, touch, cells);
        dfs(i, j - 1, n, m, board, vis, touch, cells);
    }
      void solve(vector<vector<char>>& board) {
          int n = board.size();
          if (n == 0) return;
          int m = board[0].size();
          vector<vector<bool>> vis(n, vector<bool>(m, false));
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    bool touch = false;
                      vector<pair<int, int>> cells;
                      dfs(i, j, n, m, board, vis, touch, cells);
                      if (!touch) {
                        for (auto x : cells) {
                            board[x.first][x.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};