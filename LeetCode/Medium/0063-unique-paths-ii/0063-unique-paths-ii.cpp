class Solution {
public:
    int dp[101][101];
    vector<vector<int>> dir ={{1,0},{0,1}};
    int solve_memo(int r,int c,int &m,int &n,vector<vector<int>>& g){
        if(r>=m || c>=n) return 0;
        if (g[r][c]==1) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int paths_r_c=0;
        for(const auto &x:dir){
            int nr=r+x[0],nc=c+x[1];
            paths_r_c+=solve_memo(nr,nc,m,n,g);
        }
        dp[r][c]=paths_r_c;
        return dp[r][c];
    }
    int solve_tab(int r,int c,int &m,int &n,vector<vector<int>>& g){
        dp[0][0]=(g[0][0]==1)?0:1;
        for(int i=1;i<n;i++) dp[0][i]=(g[0][i]==1)?0:dp[0][i-1];
        for(int i=1;i<m;i++) dp[i][0]=(g[i][0]==1)?0:dp[i-1][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(g[i][j]!=1) dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[m-1][n-1];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        return solve_tab(0,0,m,n,obstacleGrid);
    }
};