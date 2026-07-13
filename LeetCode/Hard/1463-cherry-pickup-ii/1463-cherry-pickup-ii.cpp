class Solution {
public:
    int m,n;
    int dp[70][70][70];
    int solve_memo(int i,int j1,int j2,vector<vector<int>>& grid){
        if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e8;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int cherries=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                cherries+= solve_memo(i+1,j1+y,j2+x,grid);
                maxi=max(maxi,cherries);
            }
        }
        dp[i][j1][j2]=maxi;
        return maxi;
    }
    int solve_tab(vector<vector<int>>& grid){
        for(int j1=0;j1<=n-1;j1++){
            for(int j2=0;j2<=n-1;j2++){
                dp[m-1][j1][j2]=(j1==j2)?grid[m-1][j1]:grid[m-1][j1]+grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<=n-1;j1++){
                for(int j2=0;j2<=n-1;j2++){
                    int maxi=-1e8;;
                    int cherries=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            if(j1+y >= 0 && j1+y < n && j2+x >= 0 && j2+x < n) {
                                int cherries = (j1==j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                                cherries += dp[i+1][j1+y][j2+x];
                                maxi = max(maxi, cherries);
                            }
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][n-1];

    }
    int solve_space(vector<vector<int>>& grid){
        int front [70][70];
        int crr [70][70];
        for(int j1=0;j1<=n-1;j1++){
            for(int j2=0;j2<=n-1;j2++){
                front[j1][j2]=(j1==j2)?grid[m-1][j1]:grid[m-1][j1]+grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<=n-1;j1++){
                for(int j2=0;j2<=n-1;j2++){
                    int maxi=-1e8;;
                    int cherries=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            if(j1+y >= 0 && j1+y < n && j2+x >= 0 && j2+x < n) {
                                int cherries = (j1==j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                                cherries += front[j1+y][j2+x];
                                maxi = max(maxi, cherries);
                            }
                        }
                    }
                    crr[j1][j2]=maxi;
                }
            }
            for(int j1=0; j1<n; j1++) {
                for(int j2=0; j2<n; j2++) {
                    front[j1][j2] = crr[j1][j2];
                }
            }
        }
        return front[0][n-1];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,0,sizeof(dp));
        return solve_tab(grid);
    }
};