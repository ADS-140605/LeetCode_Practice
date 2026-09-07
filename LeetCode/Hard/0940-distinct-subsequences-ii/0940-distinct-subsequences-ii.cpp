class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD=1e9 +7;
        int n=s.length();
        if (n==1) return 1;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%MOD;
            for(int j=i-2;j>=0;j--){
                if(s[j]==s[i-1]){
                    dp[i]=(dp[i]-dp[j]+MOD)%MOD;
                    break;
                }
            }
        }
        return (dp[n]-1 +MOD)%MOD;
    }
};