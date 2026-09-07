class Solution {
public:

    vector<int> helper(int V, vector<vector<int>>& edges, int source) {

        vector<int> dist(V + 1, INT_MAX);
        dist[source] = 0;

        vector<vector<pair<int, int>>> graph(V + 1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            graph[u].push_back({v, w});
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, source});

        while (!pq.empty()) {
            int distance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (distance > dist[u])
                continue;

            for (int i = 0; i < graph[u].size(); i++) {

                int v = graph[u][i].first;
                int edge = graph[u][i].second;

                if (dist[u] + edge < dist[v]) {
                    dist[v] = dist[u] + edge;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist = helper(n, times, k);

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
    }
};