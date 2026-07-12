class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int dp[2001][2001];
    
    bool solve(vector<int>& stones,int crr_idx,int k){
        if(crr_idx==n-1) return true;
        if(k<0) return false;
        if(dp[crr_idx][k]!=-1) return dp[crr_idx][k];
        
        bool result=false;
        for(int next_k=k-1;next_k<=k+1;next_k++){
            if (next_k<=0) continue;
            if(mp.find(stones[crr_idx]+next_k)!=mp.end()){
                result=result || solve(stones,mp[stones[crr_idx]+next_k],next_k);
            }
        }
        dp[crr_idx][k]=result;
        return result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        memset(dp,-1,sizeof(dp));
        n=stones.size();
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        return solve(stones,mp[0],0);
    }
};