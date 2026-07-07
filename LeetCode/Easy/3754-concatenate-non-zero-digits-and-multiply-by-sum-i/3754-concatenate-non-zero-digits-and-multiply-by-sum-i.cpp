class Solution {
public:
    long long sumAndMultiply(int n) {
        auto sum=[=](int n){
            long long ans=0,x=0;
            int k=0;
            while(n>0){
                ans+=n%10;
                if(n%10!=0){
                    int p=n%10,j=k;
                    while(j>0){
                        p*=10;j--;
                    }
                    k++;
                    x+=p;
                }
                n/=10;
            }
            return ans*x;
        };
        return sum(n);
    }
};