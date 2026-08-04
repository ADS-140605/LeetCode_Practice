class Solution{
public:
    int maximumUnits(vector<vector<int>>& b,int truckSize){
        sort(b.begin(),b.end(),[](auto &a,auto &c){return a[1]>c[1];});
        int ans=0;
        for(auto &x:b){
            int take=min(truckSize,x[0]);
            ans+=take*x[1];
            truckSize-=take;
            if(!truckSize)break;
        }
        return ans;
    }
};