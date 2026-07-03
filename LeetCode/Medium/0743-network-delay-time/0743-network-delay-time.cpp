class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Generating adj list ;
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto &e: times) adj[e[0]].push_back({e[1],e[2]});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();
            if (d>dist[node]) continue;
            for(const auto&[neigh,wt]:adj[node]){
                if(dist[node]+wt<dist[neigh]){
                    dist[neigh]=dist[node]+wt;
                    pq.push({dist[node]+wt,neigh});
                }
            }
        }
        int ans = 0;
        for (int i=1;i<= n;i++) {
            if (dist[i]==INT_MAX) return -1;
            ans=max(ans, dist[i]);
        }
        
        return ans;
    }
};