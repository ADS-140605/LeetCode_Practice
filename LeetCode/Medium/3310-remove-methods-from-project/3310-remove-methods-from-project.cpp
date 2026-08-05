class Solution {
public:
    vector<bool> v;
    void dfs(int u,vector<vector<int>>& adj){
        v[u]=true;
        for(auto x:adj[u]){
            if(!v[x]) dfs(x,adj);
        }
    }
    vector<int> remainingMethods(int n,int k,vector<vector<int>>& e){
        vector<vector<int>> adj(n);
        v.assign(n,false);
        for(auto &x:e) adj[x[0]].push_back(x[1]);
        dfs(k,adj);
        for(auto &x:e){
            if(!v[x[0]] && v[x[1]]){
                vector<int> ans;
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!v[i]) ans.push_back(i);
        }
        return ans;
    }
};