class Solution {
    vector<int> parent;
    vector<int> nodeRank;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); 
    }

    bool unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU == rootV) {
            return true; 
        }
        
        if (nodeRank[rootU] < nodeRank[rootV]) {
            parent[rootU] = rootV;
        } else if (nodeRank[rootU] > nodeRank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            nodeRank[rootU]++;
        }
        
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        nodeRank.resize(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        for (const auto& edge : edges) {
            if (unionSet(edge[0], edge[1])) {
                return edge;
            }
        }
        
        return {};
    }
};