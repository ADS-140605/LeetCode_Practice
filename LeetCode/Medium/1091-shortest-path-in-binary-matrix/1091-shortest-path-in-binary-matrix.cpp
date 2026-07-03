class Solution {
public:
    using ti = tuple<int,int,int>;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        vector<vector<int>> dist(n,vector(n,INT_MAX));

        auto bounds=[&](int x,int y){
            return x<n && x>=0 && y<n && y>=0;
        };
        priority_queue<ti,vector<ti>,greater<>> pq;
        dist[0][0]=1;
        pq.push({1,0,0});
        while(!pq.empty()){
            auto[d,x,y]=pq.top();
            pq.pop();
            if(d>dist[x][y]) continue;
            if(x==n-1 && y==n-1) return d;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(bounds(x+i,y+j) && grid[x+i][y+j]==0 && dist[x][y]+1<dist[x+i][y+j]){
                        dist[x+i][y+j]=dist[x][y]+1;
                        pq.push({dist[x+i][y+j],x+i,y+j});
                    }
                }
            }
        }
        return (dist[n-1][n-1]==INT_MAX)?-1:dist[n-1][n-1];

    }
};