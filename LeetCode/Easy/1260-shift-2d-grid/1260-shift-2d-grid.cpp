class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid,int k) {
        int m=grid.size(),n=grid[0].size();
        k%=m*n;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int curr=i*n+j;
                int next=(curr+k)%(m*n);
                ans[next/n][next%n]=grid[i][j];
            }
        }
        return ans;
    }
};