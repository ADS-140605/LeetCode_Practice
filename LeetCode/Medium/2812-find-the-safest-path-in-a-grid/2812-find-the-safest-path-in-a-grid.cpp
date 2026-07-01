class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        // multi-source BFS from all thieves
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]==INT_MAX){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        // dijkstra:like max-heap to find safest path
        // {safeness,x,y} —safeness=min dist seen in the path
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        pq.push({dist[0][0],0,0});
        while(!pq.empty()){
            auto [safe,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==n-1) return safe;
            if(visited[x][y]) continue;
            visited[x][y]=true;
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny]){
                    pq.push({min(safe,dist[nx][ny]),nx,ny});
                }
            }
        }
        return 0;
    }
};