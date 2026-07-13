class Solution {
public:
    int dp[101][101];
    vector<vector<int>> dir ={{1,0},{0,1}};
    int solve(int r,int c,int &m,int &n,vector<vector<int>>& g){
        if(r>=m || c>=n) return 0;
        if (g[r][c]==1) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int paths_r_c=0;
        for(const auto &x:dir){
            int nr=r+x[0],nc=c+x[1];
            paths_r_c+=solve(nr,nc,m,n,g);
        }
        dp[r][c]=paths_r_c;
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        return solve(0,0,m,n,obstacleGrid);
    }
};