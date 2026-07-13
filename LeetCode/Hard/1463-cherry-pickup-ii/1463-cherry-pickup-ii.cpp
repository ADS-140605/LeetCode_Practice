class Solution {
public:
    int m,n;
    int dp[70][70][70];
    int solve(int i,int j1,int j2,vector<vector<int>>& grid){
        if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e8;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e8;;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int cherries=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                cherries+= solve(i+1,j1+y,j2+x,grid);
                maxi=max(maxi,cherries);
            }
        }
        dp[i][j1][j2]=maxi;
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n-1,grid);
    }
};