class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            if(i!=n)ans^=nums[i]^i;
            else ans^=i;
        }
        return ans;
    }
};