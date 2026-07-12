class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        int n=arr.size();
        vector<int> ans(arr.begin(),arr.end());
        sort(ans.begin(),ans.end());
        unordered_map<int,int> mp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(mp.find(ans[i])==mp.end()){
                mp[ans[i]]=rank++;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};