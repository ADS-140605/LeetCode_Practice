class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];
        
        vector<int> w(n-k+1);
        for(int i=0;i<=n-k;i++)
            w[i]=pre[i+k]-pre[i];
        
        vector<int> l(n-k+1),r(n-k+1);
        
        l[0]=0;
        for(int i=1;i<=n-k;i++)
            l[i]=(w[i]>w[l[i-1]]? i: l[i-1]);
        
        r[n-k]=n-k;
        for(int i=n-k-1;i>=0;i--)
            r[i]=(w[i]>=w[r[i+1]] ? i:r[i+1]);
        
        vector<int> ans;
        int best=0;
        
        for(int j=k;j<=n-2*k;j++){
            int left=l[j-k];
            int right=r[j+k];
            int cur=w[left]+w[j]+w[right];
            
            if(ans.empty() || cur>best){
                best=cur;
                ans={left,j,right};
            }
        }
        
        return ans;
    }
};