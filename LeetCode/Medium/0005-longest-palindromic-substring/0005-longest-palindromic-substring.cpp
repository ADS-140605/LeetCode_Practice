class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0) return "";
        int start=0,maxlen=1;
        auto expand=[&](int l,int r){
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>maxlen){
                maxlen=len;
                start=l+1;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxlen);
    }
};