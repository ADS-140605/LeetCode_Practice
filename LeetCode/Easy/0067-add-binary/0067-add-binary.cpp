class Solution {
public:
    string addBinary(string a, string b) {
        int c=0;
        int l=a.size()-1,r=b.size()-1;
        string ans;
        while(l>=0 || r>=0 || c){
            int sum=c;
            if(l>=0) sum+=a[l--]-'0';
            if(r>=0) sum+=b[r--]-'0';
            ans.push_back(sum%2+'0');
            c=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};