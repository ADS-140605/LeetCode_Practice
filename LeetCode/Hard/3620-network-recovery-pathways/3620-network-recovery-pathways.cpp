class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
        int low = 2e9, high = -1;
        for(const auto& e : edges) {
            low = min(low, e[2]);
            high = max(high, e[2]);
        }
        auto check = [&](int mid) {
            vector<long long> dist(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            dist[0] = 0;
            pq.push({0, 0});
            while(!pq.empty()){
                auto [d, node] = pq.top();
                pq.pop();
                if(d > dist[node]) continue;
                if(node == n - 1) return dist[n - 1] <= k;
                for(auto [neigh, wt] : adj[node]){
                    if(wt < mid || (!online[neigh] && neigh != n - 1)) continue;
                    if(d + wt < dist[neigh]){
                        dist[neigh] = d + wt;
                        pq.push({dist[neigh], neigh});
                    }
                }
            }
            return dist[n - 1] <= k;
        };
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};