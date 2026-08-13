class Solution {
public:
    void dfs(int i , int j , int n , int m , vector<vector<char>>& board , vector<vector<bool>>& vis , bool& touchesBorder , vector<pair<int, int>>& region ){
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O' || vis[i][j]){
            return ;
        }

        vis[i][j] = true ;
        region.push_back({i, j}) ;
        
        if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
            touchesBorder = true ;
        }
        
        dfs(i-1 , j , n , m , board , vis , touchesBorder , region ) ;
        dfs(i+1 , j , n , m , board , vis , touchesBorder , region ) ;
        dfs(i , j-1 , n , m , board , vis , touchesBorder , region ) ;
        dfs(i , j+1 , n , m , board , vis , touchesBorder , region ) ;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size() ;
        if(n == 0) return ;
        int m = board[0].size() ;
        
        vector<vector<bool>> vis(n, vector<bool>(m, false)) ;
        
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){
                if(board[i][j] == 'O' && !vis[i][j]){
                    bool touchesBorder = false ;
                    vector<pair<int, int>> region ;
                    
                    dfs(i , j , n , m , board , vis , touchesBorder , region ) ;
                    
                    if(touchesBorder == false){
                        for(auto coord : region){
                            board[coord.first][coord.second] = 'X' ;
                        }
                    }
                }
            }
        }
    }
};
