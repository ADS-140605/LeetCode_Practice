class Solution {
public:
    using ll =long long;
    int findNthDigit(ll n) {
        ll d=1,c=9,s=1;
        while(n>d*c){
            n-=d*c;
            d++;
            c*=10;
            s*=10;
        }
        ll num=s+(n-1)/d;
        ll pos=(n-1)%d;
        return to_string(num)[pos]-'0';
    }
};