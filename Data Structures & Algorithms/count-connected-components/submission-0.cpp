class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visit, int count){
        visit[u] = true;
        for(auto &v : adj[u]){
            if(!visit[v]){
                dfs(v,adj,visit,count);
            }
        }
        
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visit(n,false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visit[i]){
                dfs(i,adj,visit,count);
                count++;
            }
        }
        return count;

    }
};
