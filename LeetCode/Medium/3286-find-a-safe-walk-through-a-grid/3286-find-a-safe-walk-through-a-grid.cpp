class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        // dijkstra: min-heap to find least health lost
        // {damage,x,y}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        pq.push({dist[0][0],0,0});
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!pq.empty()){
            auto [d,x,y]=pq.top();
            pq.pop();
            if(visited[x][y]) continue;
            visited[x][y]=true;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){
                    int nd=d+grid[nx][ny];
                    if(nd<dist[nx][ny]){
                        dist[nx][ny]=nd;
                        pq.push({nd,nx,ny});
                    }
                }
            }
        }
        return health-dist[m-1][n-1]>=1;
    }
};