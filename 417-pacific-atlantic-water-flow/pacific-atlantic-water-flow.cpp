class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        int n = heights.size();
        int m = heights[0].size();
        
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (!visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(heights, nr, nc, visited);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, m - 1, atlantic);
        }
        
        for (int j = 0; j < m; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, n - 1, j, atlantic);
        }
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};