class Solution {
public:
    bool iscycle(int src, vector<bool> &vist, vector<bool> &recpath, vector<vector<int>>& edges){
        vist[src] = true;
        recpath[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src){
                if(!vist[v]){
                    if(iscycle(v,vist,recpath,edges)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }

        recpath[src] = false;
        return false; 
    }
    bool canFinish(int n, vector<vector<int>>& edges){
        vector<bool> vist(n,false);
        vector<bool> recpath(n,false);

        for(int i=0; i<n; i++){
            if(!vist[i]){
                if(iscycle(i,vist,recpath,edges)){
                    return false;
                }
            }
        }
        return true;
    }
};
