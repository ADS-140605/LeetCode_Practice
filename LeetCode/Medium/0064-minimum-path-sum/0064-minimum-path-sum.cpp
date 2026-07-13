class Solution {
public:
    int m,n;
    int dp[201][201];
    vector<vector<int>> dir={{0,1},{1,0}};
    int solve(int r,int c,vector<vector<int>>& grid){
        if(r>=m||c>=n) return INT_MAX-10;
        if (r==m-1 && c==n-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int minpath=INT_MAX-10;
        for(const auto &x:dir){
            int nr=r+x[0],nc=c+x[1];
            minpath=min(minpath,solve(nr,nc,grid));
        }
        dp[r][c]=grid[r][c]+minpath;
        return dp[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};