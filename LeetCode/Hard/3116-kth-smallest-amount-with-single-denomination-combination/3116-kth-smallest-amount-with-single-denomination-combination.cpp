class Solution {
public:
    using ll =long long;
    ll lcm(ll a,ll b){
        return a/__gcd(a,b)*b;
    }
    ll cnt(vector<int>& coins,ll x){
        int n=coins.size();
        ll ans=0;
        for(int mask=1;mask<(1<<n);mask++){
            ll val=1;
            int bits=0;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    bits++;
                    val=lcm(val,coins[i]);
                    if(val>x){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag) continue;
            if(bits%2) ans+=x/val;
            else ans-=x/val;
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins,int k) {
        int n=coins.size();

        ll l=1;
        ll h=1LL*(*min_element(coins.begin(),coins.end()))*k;
        while(l<h){
            ll mid=l+(h-l)/2;
            if(cnt(coins,mid)>=k)
                h=mid;
            else
                l=mid+1;
        }

        return l;
    }
};