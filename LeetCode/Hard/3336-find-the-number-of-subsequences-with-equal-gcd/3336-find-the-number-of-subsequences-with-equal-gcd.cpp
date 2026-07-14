class Solution {
public:
    using ll=long long;
    const int MOD=1e9+7;
    // int dp[201][201][201][4];

    int solve_tab(vector<int>& nums){
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(mx+1,vector<int>(mx+1,0));
        for(int gcd1=1;gcd1<=mx;gcd1++){
            dp[gcd1][gcd1]=1;
        }
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> crr(mx+1,vector<int>(mx+1,0));
            for(int gcd1=0;gcd1<=mx;gcd1++){
                for(int gcd2=0;gcd2<=mx;gcd2++){
                    ll ex=dp[gcd1][gcd2];
                    ll s1=dp[__gcd(gcd1,nums[i])][gcd2];
                    ll s2=dp[gcd1][__gcd(gcd2,nums[i])];
                    crr[gcd1][gcd2]=(ex+s1+s2)%MOD;
                }
            }
            dp=move(crr);
        }
        return dp[0][0];
    }
    // int solve_rec(int i,int j1,int j2,vector<int>& nums,int gcd1,int gcd2){
    //     if (i<0) return (j1>0 && j2>0 && gcd1==gcd2);
    //     int mask =(j1>0)*2+(j2>0);
    //     if (dp[i][gcd1][gcd2][mask] !=-1) return dp[i][gcd1][gcd2][mask];
    //     ll s1= solve_rec(i-1,j1+1,j2,nums,__gcd(nums[i],gcd1),gcd2);
    //     ll s2= solve_rec(i-1,j1,j2+1,nums,gcd1,__gcd(gcd2,nums[i]));
    //     ll ex= solve_rec(i-1,j1,j2,nums,gcd1,gcd2);
    //     return dp[i][gcd1][gcd2][mask]=(s1+s2+ex)%MOD;
    // }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        return solve_tab(nums);
    }
};