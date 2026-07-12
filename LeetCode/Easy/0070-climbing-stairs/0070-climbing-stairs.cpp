class Solution {
public:
    void solve(int n, vector<int>& dp) {
        if (dp[n] != -1) return;
        if (n == 0) { dp[n] = 1; return; }
        if (n == 1) { dp[n] = 1; return; }
        solve(n - 1, dp);
        solve(n - 2, dp);
        dp[n] = dp[n - 1] + dp[n - 2];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        solve(n, dp);
        return dp[n];
    }
};