class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' ') i++;
        if (i==n) return 0;
        if(!(s[i]=='+'||s[i]=='-'|| isdigit(s[i]))) return 0;
        int sign=1;
        if(i<n && (s[i]=='+'||s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        long long res=0;
        while(i<n && isdigit(s[i])){
            res= res*10 + (s[i]-'0');
            if(sign==1 && res>INT_MAX) return INT_MAX;
            if(sign==-1 && -res<INT_MIN) return INT_MIN;
            i++;
        }
        return (int)sign*res;
    }
};