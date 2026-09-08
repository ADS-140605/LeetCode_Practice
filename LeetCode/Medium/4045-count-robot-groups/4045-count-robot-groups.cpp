class Solution {
public:
    int countGroups(vector<int>& p, vector<int>& s, int d) {
        int n=p.size();
        int ans=1;
        int v=s[n-1];
        for(int i=n-2;i>=0;i--){
            if(p[i+1]-p[i]<=d || s[i]>v){
                continue;
            }
            ans++;
            v=s[i];
        }
        return ans;
    }
};