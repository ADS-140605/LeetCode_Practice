class Solution {
public:
    int minimumDeletions(vector<int>& nu) {
        int n=nu.size();
        int mi=0,mx=0;
        for(int i=0;i<n;i++){
            if(nu[i]<nu[mi]){
                mi=i;
            }
            if(nu[i]>nu[mx]){
                mx=i;
            }
        }
        int dl=max(mi,mx)+1,dr=n-min(mi,mx);
        int dm=(mi>mx)?(mx+1)+(n-mi):(mi+1)+(n-mx);
        return min({dl,dr,dm});
    }
};