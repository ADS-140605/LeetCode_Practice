class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> id(n,0);
        // sepearting chunks {path1 :id=0},{path2,id=1}......
        // {2,5,6,8} : index :{0,1,2,3}
        // {1,2,3},{0} : id:{0,0,0,1}
        for(int i=1;i<n;i++) id[i]=id[i-1]+(((nums[i]-nums[i-1])>maxDiff)?1:0); 
        vector<bool> ans;
        for(const auto& x:queries){
            if(id[x[0]]==id[x[1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};