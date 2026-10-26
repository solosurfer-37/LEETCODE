class Solution {
public:
long long dfs(int i , int j , int n , int m ,vector<vector<int>>& grid , vector<vector<bool>>& vis ){
    if(i < 0 || j < 0 || n <= i || m <= j || vis[i][j] || grid[i][j] == 0 ){
        return 0 ;

    }
    vis[i][j] = true ;


    return grid[i][j]+dfs(i+1, j, n, m, grid,vis)+ dfs(i-1, j, n, m, grid,vis)+ dfs(i, j+1, n, m, grid,vis)+dfs(i, j-1, n, m, grid,vis); 
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        long long sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    sum = dfs(i, j, n, m, grid,vis);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};