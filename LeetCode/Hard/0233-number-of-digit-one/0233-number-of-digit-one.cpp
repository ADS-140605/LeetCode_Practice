class Solution {
public:
    using ll=long long;
    int solve(int v){
        int ct=0;
        string str=to_string(v);
        for(int i=0;i<str.length();i++){
            if(str[i]=='1'){
                ct++;
            }
        }
        return ct;
    }
    int countDigitOne(int n) {
        // int ans=0;
        // for(n;n>0;n--){
        //     ans+=solve(n);
        // }
        // return ans;
        ll ans=0;
        for(ll i=1;i<=n;i*=10){
            ll a=n/i;
            ll b=n%i;
            ans+=(a+8)/10*i;
            if(a%10==1) ans+=b+1;
        }
        return ans;
    }
};