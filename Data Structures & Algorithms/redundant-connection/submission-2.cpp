class Solution {
public:
    bool dfs(int u, int v,
             unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {

        if (u == v)
            return true;

        visited[u] = true;

        for (int nei : adj[u]) {
            if (!visited[nei]) {
                if (dfs(nei, v, adj, visited))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            // Fresh visited array for this DFS
            vector<bool> visited(n + 1, false);

            if (adj.count(u) && adj.count(v) &&
                dfs(u, v, adj, visited)) {

                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};