class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int cnt0=0;
        for(int i=0;i<n;i++){
            char exp=(i%2==0)?'0':'1';
            if (exp!=s[i]) cnt0++;
        }
        int cnt1=n-cnt0;
        return min(cnt1,cnt0);
    }
};