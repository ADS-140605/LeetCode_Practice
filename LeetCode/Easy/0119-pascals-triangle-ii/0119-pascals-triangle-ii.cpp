class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> dp(r+1,1);
        for(int i=1;i<=r;i++){
            // vector<int> crr(r+1,1);
            for(int j=i-1;j>0;j--){
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp;
    }
};