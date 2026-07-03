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

static const bool __boost = [] ()
{
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    return std::ios_base::sync_with_stdio (false);
}();

// Custom memory pool for dynamic allocation using a pre-allocated buffer
const size_t BUFFER_SIZE = 0x30000000;
alignas (std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *
operator new (size_t size)
{
    constexpr std::size_t alignment = alignof (std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void
operator delete (void * /*unused*/, unsigned long /*unused*/) noexcept
{
}
void
operator delete (void * /*unused*/) noexcept
{
}
void
operator delete[] (void * /*unused*/) noexcept
{
}
void
operator delete[] (void * /*unused*/, size_t /*unused*/) noexcept
{
}