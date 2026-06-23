#define ll long long int
#define mod 1000000007
//Had to look for solution learned : dp+prefix/suffix
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        ll m=r-l+1;
        if(n==1) return m%mod;
        vector<ll> up(m+1,0), down(m+1,0);
        for(int v=1;v<=m;v++){
            up[v]=v-1;
            down[v]=m-v;
        }
        int len=3;
        while(len<=n){
            vector<ll> nu(m+1,0), nd(m+1,0);
            ll pref=0;
            for(int v=1;v<=m;v++){
                nu[v]=pref;
                pref=(pref+down[v])%mod;
            }
            ll suf=0;
            int v=m;
            while(v>=1){
                nd[v]=suf;
                suf=(suf+up[v])%mod;
                v--;
            }
            up=nu;
            down=nd;
            len++;
        }
        ll ans=0;
        for(int v=1;v<=m;v++) ans=(ans+up[v]+down[v])%mod;
        return ans;
    }
};