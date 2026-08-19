class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        state[node] = 1;
        for (int next : graph[node]) {
            if (state[next] == 1) {
                return false;
            }
            if (state[next] == 0 && !dfs(next, graph, state)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> state(n, 0);
        for (int i = 0; i < n ; i++) {
            if (dfs(i, graph, state)) {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};