class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int pre=n+1;
        vector<int> cnt(2*n+2,0),acc(2*n+2,0);
        cnt[pre]=1;
        acc[pre]=1;
        long long res=0;
        for(int x:nums){
            pre+=(x==target?1:-1);
            cnt[pre]++;
            acc[pre]=acc[pre-1]+cnt[pre];
            res+=acc[pre-1];
        }
        return res;
    }
};