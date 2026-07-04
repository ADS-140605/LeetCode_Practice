class Solution {
public:
    using P=pair<int,int>;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n+1);
        for (const auto& e : roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int> min_edge(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<>> pq;
        pq.push({INT_MAX,1});
        while(!pq.empty()){
            auto [e,crr]=pq.top();
            pq.pop();
            if(e>min_edge[crr]) continue;
            for(const auto& [neigh,wt]: adj[crr]){
                int new_score=min(wt,e);
                if(new_score<min_edge[neigh] || wt<min_edge[neigh]){
                    min_edge[neigh]=min({min_edge[neigh],wt,new_score});
                    pq.push({min_edge[neigh],neigh});
                }
            }
        }
        return min_edge[n];
    }
};