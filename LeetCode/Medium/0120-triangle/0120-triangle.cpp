class Solution {
public:
    // int dp[201][201];
    int n;
    int solve(vector<vector<int>>& triangle){
        vector<int> prev;
        prev.push_back(triangle[0][0]);
        for(int i=1;i<n;i++){
            vector<int> crr;
            crr.push_back(prev[0]+triangle[i][0]);
            int m=triangle[i].size();
            int minp=INT_MAX-(int)1e4;
            for(int j=1;j<m-1;j++){
                minp=triangle[i][j]+min(prev[j],prev[j-1]);
                crr.push_back(minp);
            }
            crr.push_back(prev[m-2]+triangle[i][m-1]);
            prev=crr;
        }
        return *min_element(prev.begin(),prev.end());

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        // memset(dp,-1,sizeof(dp));
        return solve(triangle);
    }
};