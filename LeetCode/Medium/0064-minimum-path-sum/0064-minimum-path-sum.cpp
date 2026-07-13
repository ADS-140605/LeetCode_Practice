class Solution {
public:
    int m,n;
    int dp[201][201];
    vector<vector<int>> dir={{0,1},{1,0}};
    int memo(int r,int c,vector<vector<int>>& grid){
        if(r>=m||c>=n) return INT_MAX-10;
        if (r==m-1 && c==n-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int minpath=INT_MAX-10;
        for(const auto &x:dir){
            int nr=r+x[0],nc=c+x[1];
            minpath=min(minpath,memo(nr,nc,grid));
        }
        dp[r][c]=grid[r][c]+minpath;
        return dp[r][c];
    }
    int tab(vector<vector<int>>& grid){
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++) dp[0][i]=grid[0][i]+dp[0][i-1];
        for(int i=1;i<m;i++) dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        // return memo(0,0,grid);
        return tab(grid);
        // return dp[m-1][n-1];
    }
};