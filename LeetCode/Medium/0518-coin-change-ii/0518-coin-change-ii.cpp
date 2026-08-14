class Solution {
public:
    long long dp[301][5001];
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
        vector<unsigned long long> odp(a+1,0);
        odp[0]=1;
        for(int i=c.size()-1;i>=0;i--){
            for(int j=c[i];j<=a;j++){
                odp[j]+=odp[j-c[i]];
            }
        }
        return odp[a];
        return solve(0,a,c);
    }
};