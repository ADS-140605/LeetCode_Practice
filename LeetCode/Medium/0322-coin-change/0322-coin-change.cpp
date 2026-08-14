class Solution {
public:
    // int dp[13][10001];
    // int solve(int i,vector<int>& c, int a){
    //     if(a==0) return 0;
    //     if(i>=c.size()) return 1e8;
    //     if(dp[i][a]!=-1) return dp[i][a];
    //     int t=(c[i]>a)?1e8:1+solve(i,c,a-c[i]);
    //     int nt=solve(i+1,c,a);
    //     return dp[i][a]=min(t,nt);
    // }
    int coinChange(vector<int>& c, int a) {
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(0,coins,amount);
        // return (ans>=1e8)?-1:ans;
        int n=c.size();
        vector<vector<int>> dp(n+1,vector<int>(a+1,1e8));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=a;j++){
                int nt=dp[i+1][j];
                int t =(c[i]>j)? 1e8: 1+dp[i][j-c[i]];
                dp[i][j]=min(nt,t);
            }
        }
        return (dp[0][a]>=1e8) ?-1 :dp[0][a];
    }
};