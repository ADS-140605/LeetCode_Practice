#define ll long long int
#define mod 1000000007

// Looked solution learned about matrix exponentiation and all 
// typed on my own but will definetly look back to it 
class Solution {
public:
    vector<vector<ll>> multiply(vector<vector<ll>>& a,vector<vector<ll>>& b){
        int n=a.size();
        vector<vector<ll>> c(n,vector<ll>(n,0));
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(a[i][k]==0) continue;
                for(int j=0;j<n;j++){
                    if(b[k][j]==0) continue;
                    c[i][j]=(c[i][j]%mod+(a[i][k]%mod*b[k][j]%mod)%mod)%mod;
                }
            }
        }
        return c;
    }

    vector<vector<ll>> power(vector<vector<ll>> base,long long exp){
        int n=base.size();
        vector<vector<ll>> res(n,vector<ll>(n,0));
        for(int i=0;i<n;i++) res[i][i]=1;
        while(exp){
            if(exp&1) res=multiply(res,base);
            base=multiply(base,base);
            exp>>=1;
        }
        return res;
    }

    int zigZagArrays(int n,int l,int r){
        int m=r-l+1;
        int s=2*m;
        auto up=[&](int v){return v-1;};
        auto dn=[&](int v){return m+(v-1);};
        vector<vector<ll>> trans(s,vector<ll>(s,0));
        for(int v=1;v<=m;v++){
            for(int u=1;u<v;u++){
                trans[up(v)][dn(u)]=1;
            }
            for(int u=v+1;u<=m;u++){
                trans[dn(v)][up(u)]=1;
            }
        }
        vector<ll> dp2(s,0);
        for(int v=1;v<=m;v++){
            dp2[up(v)]=v-1;
            dp2[dn(v)]=m-v;
        }
        vector<vector<ll>> res=power(trans,n-2);
        vector<ll> dpn(s,0);
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                dpn[i]=(dpn[i]+res[i][j]*dp2[j])%mod;
            }
        }
        ll ans=0;
        for(ll x:dpn) ans=(ans+x)%mod;
        return ans;
    }
};