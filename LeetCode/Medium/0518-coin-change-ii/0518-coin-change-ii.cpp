class Solution {
public:
    int dp[301][5001];
    int solve(int i,int a, vector<int>& c){
        if(a==0) return 1;
        if(i>=c.size()) return 0;
        if(dp[i][a]!=-1) return dp[i][a];
        int nt=solve(i+1,a,c);
        int t=(c[i]>a)?0:solve(i,a-c[i],c);
        return dp[i][a]=nt+t;
    }
    int change(int a, vector<int>& c) {
        memset(dp,-1,sizeof(dp));
        return solve(0,a,c);
    }
};