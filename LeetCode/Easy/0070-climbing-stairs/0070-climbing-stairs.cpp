class Solution {
public:
    // void solve(int n, vector<int>& dp) {
    //     if (dp[n] != -1) return;
    //     if (n == 0) { dp[n] = 1; return; }
    //     if (n == 1) { dp[n] = 1; return; }
    //     solve(n - 1, dp);
    //     solve(n - 2, dp);
    //     dp[n] = dp[n - 1] + dp[n - 2];
    // }

    int climbStairs(int n) {
        // vector<int> dp(n + 1, -1);
        int p1=1,p2=1;
        // solve(n, dp);
        for(int i=2;i<=n;i++){
            int temp=p1+p2;
            // dp[i]=dp[i-1]+dp[i-2];
            p1=p2;
            p2=temp;
        }
        return p2;
    }
};