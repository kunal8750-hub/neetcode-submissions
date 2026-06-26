class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1){
            return 0;
        }
        grid[i][j] = 0;
        int area = 1;

        area += dfs(i-1,j,grid,m,n);
        area += dfs(i,j+1,grid,m,n);
        area += dfs(i+1,j,grid,m,n);
        area += dfs(i,j-1,grid,m,n);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i,j,grid,m,n);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};
