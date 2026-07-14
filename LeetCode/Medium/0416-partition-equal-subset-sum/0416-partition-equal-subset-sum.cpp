class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int total_sum=accumulate(arr.begin(),arr.end(),0);
        if(total_sum&1) return false;
        vector<bool> dp(total_sum+1,0);
        int target =total_sum/2;
        dp[0]=true;
        if(arr[0]<=total_sum){
            dp[arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            vector<bool> crr(target+1,0);
            crr[0]=true;
            for(int t=1;t<=target;t++){
                bool included = (t-arr[i]>=0)? dp[t-arr[i]]:false;
                bool excluded = dp[t];
                crr[t]=included || excluded;
            }
            dp=crr;
        }
        return dp[total_sum/2];;
    }
};