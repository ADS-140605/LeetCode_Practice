class Solution {
public:
    int minOperations(int n) {
        // unsigned int x=n;
        // int c=popcount(static_cast<unsigned int>(n));
        int ans=0;
        while(n>0){
            if((n&1)==0) n>>=1;
            else if ((n&3)==1) n--,ans++;
            else n++,ans++;
        }
        return ans;
    }
};