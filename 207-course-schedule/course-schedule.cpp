class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& adj, vector<int>& state ){
        state[curr] = 1 ;
        for(int v : adj[curr]){
            if(state[v] == 1 ){
                return true ;
            }
            if(state[v] == 0 ){
                if(dfs(v , adj , state )){
                    return true ;
                }
            }
        }
        state[curr ] = 2 ;
        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            
            adj[pre[1]].push_back(pre[0]); 
        }
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) {
                    return false; 
                }
            }
        }
        
        return true;
    }
};