#include <bits/stdc++.h>
class Solution {
public:
    int openLock(vector<string>& d, string target) {
        unordered_set<string> dead(d.begin(),d.end());
        if(dead.contains("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        dead.insert("0000");
        while(!q.empty()){
            auto[crr,turns]=q.front();
            q.pop();
            if(crr==target) return turns;
            for(int i=0;i<4;i++){
                for(int dir:{-1,1}){
                    string next=crr;
                    next[i]=(next[i]-'0'+dir+10)%10 +'0';
                    if(dead.find(next)==dead.end()){
                        dead.insert(next);
                        q.push({next,turns+1});
                    }
                }
            }
        }
        return -1;
    }
};