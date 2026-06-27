class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int x:nums) mp[x]++;
        int ans=1;
        if(mp.count(1)){
            int f=mp[1];
            ans=max(ans,f%2==1?f:f-1);
        }
        for(const auto& [k,v]:mp){
            if(k==1) continue;
            long long cur=k;
            int len=0;
            while(mp.count(cur) && mp[cur]>=2){
                len+=2;
                cur=cur*cur;
            }
            len+=mp.count(cur)?1:-1;
            ans=max(ans,len);
        }
        return ans;
    }
};