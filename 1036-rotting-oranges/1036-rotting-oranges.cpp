class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<pair<pair<int,int>,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int cnt1 = 0;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow  = dr[i]+r;
                int ncol = dc[i]+c;

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol] = 1;
                    cnt1++;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        if(cnt!=cnt1 ){
            return -1;
        }
        return time;
    }
};