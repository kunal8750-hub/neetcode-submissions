class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vist(m,vector<bool> (n,false));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vist[i][j] = true;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans,time);

            if(i-1>=0 && grid[i-1][j]!=0 && !vist[i-1][j]){
                q.push({{i-1,j},time+1});
                vist[i-1][j] = true;
            }

            if(j+1 < n && grid[i][j+1]!=0 && !vist[i][j+1]){
                q.push({{i,j+1},time+1});
                vist[i][j+1] = true;
            }

            if(i+1 < m && grid[i+1][j]!=0 && !vist[i+1][j]){
                q.push({{i+1,j},time+1});
                vist[i+1][j] = true;
            }

            if(j-1 >= 0 && grid[i][j-1]!=0 && !vist[i][j-1]){
                q.push({{i,j-1},time+1});
                vist[i][j-1] = true;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vist[i][j]){
                    return -1;
                }
            }
        }
        return ans;
    }
};
