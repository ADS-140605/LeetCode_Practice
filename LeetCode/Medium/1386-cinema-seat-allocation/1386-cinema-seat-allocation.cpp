class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        map<int,set<int>> mp;
        for(auto x:r) mp[x[0]].insert(x[1]);

        int ans=(n-mp.size())*2;

        for(auto &p:mp){
            auto &s=p.second;
            int cnt=0;
            bool l=0,r=0;

            for(int x=2;x<=6;x+=2){
                bool ok=1;
                for(int i=x;i<x+4;i++){
                    if(s.count(i)){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    cnt++;
                    if(x==2) l=1;
                    if(x==6) r=1;
                }
            }

            if(l && r) ans+=2;
            else if(cnt) ans++;
        }
        return ans;
    }
};