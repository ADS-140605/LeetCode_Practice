class Solution {
public:
    const long long MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<long long> ds(n+1,0),nz(n+1,0),pow10(n+1,1),nupto(n+1,0);
        int pre=ds.back();
        for(int i=0;i<n;i++){
            int j=s[i]-'0';
            if(j!=0){
                nz[i+1]=nz[i]+1;
                nupto[i+1]=(10*nupto[i]+j)%MOD;
            }else{
                nz[i+1]=nz[i];
                nupto[i+1]=nupto[i];
            }
            pow10[i+1]=(pow10[i]*10)%MOD;
            ds[i+1]+=ds[i]+j;
        }
        int m=queries.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int l = queries[i][0], r = queries[i][1];
            long long count=nz[r+1]-nz[l];
            long long x = (nupto[r+1]-nupto[l]*pow10[count]%MOD +MOD)%MOD;
            long long ss= ds[r+1]-ds[l];
            ans[i]= (int)((x*(ss%MOD))%MOD);
        }
        return ans;
    }
};