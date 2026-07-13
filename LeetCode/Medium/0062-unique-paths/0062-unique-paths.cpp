class Solution {
public:
    int maxm,maxn;
    int dp[101][101];
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int solve(int r,int c){
        if(r>maxm || c>maxn) return 0;
        if(r==maxm && c==maxn) return 1;
        if (dp[r][c]!=-1) return dp[r][c];
        int numOfPaths_r_c=0;
        for(const auto& x:dir){
            int nr=r+x[0],nc=c+x[1];
            numOfPaths_r_c+=solve(nr,nc);
        }
        dp[r][c]=numOfPaths_r_c;
        return numOfPaths_r_c;
    }
    int uniquePaths(int m, int n) {
        maxm=m-1;maxn=n-1;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);}
};