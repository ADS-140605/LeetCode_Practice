class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> dp(r+1,1);
        for(int i=1;i<=r;i++){
            vector<int> crr(r+1,1);
            for(int j=1;j<i;j++){
                crr[j]=dp[j-1]+dp[j];
            }
            dp=crr;
        }
        return dp;
    }
};