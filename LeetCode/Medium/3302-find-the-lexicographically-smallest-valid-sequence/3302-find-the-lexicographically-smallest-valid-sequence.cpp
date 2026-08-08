class Solution {
public:
    vector<int> validSequence(string a,string b) {
        int n=a.size(),m=b.size(),j=m-1;
        vector<int> suf(n+1);
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1];
            if(j>=0 && a[i]==b[j]) suf[i]++,j--;
        }
        vector<int> ans;
        bool ok=0;
        j=0;
        for(int i=0;i<n && j<m;i++){
            if(a[i]==b[j]||(!ok && suf[i+1]>=m-j-1)){
                ok|=(a[i]!=b[j]);
                ans.push_back(i);
                j++;
            }
        }
        return j==m?ans:vector<int>();
    }
};