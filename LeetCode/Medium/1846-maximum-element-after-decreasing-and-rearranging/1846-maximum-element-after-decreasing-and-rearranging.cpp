class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // TC:O(N*log(N)) SC:O(1) 
        // sort(arr.begin(), arr.end());
        // int n = arr.size();
        // arr[0] = 1;
        // for (int i = 1; i < n; i++) {
        //     arr[i] = min(arr[i], arr[i - 1] + 1);
        // }
        // return arr[n - 1];

        //TC:O(N) SC:O(N)
        int n=arr.size();
        vector<int> bucket(n+1,0);
        for(int i=0;i<n;i++){
            bucket[min(arr[i],n)]++;//upper elements clamped at n as (greedy)
        }
        int ans=0;
        for(int i=1;i<=n;i++){//due to line bucket[min(arr[i],n)] bucket[n] is filled too
            if(bucket[i]==0) continue;
            ans=min(ans+bucket[i],i);
        }
        return ans;
    }
};