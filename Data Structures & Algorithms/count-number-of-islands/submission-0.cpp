class Solution {
public: 
    void dfs(int i, int j, vector<vector<bool>> &vist,vector<vector<char>>& grid, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1' || vist[i][j]){
            return;
        }
        vist[i][j] = true;
            dfs(i-1,j,vist,grid,m,n);
            dfs(i,j+1,vist,grid,m,n);
            dfs(i+1,j,vist,grid,m,n);
            dfs(i,j-1,vist,grid,m,n);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vist(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vist[i][j]){
                    island++;
                    dfs(i,j,vist,grid,m,n);
                }
            }
        }
        return island;
    }
};
