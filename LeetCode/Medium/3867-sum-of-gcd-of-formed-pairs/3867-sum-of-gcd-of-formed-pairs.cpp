class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx= max(nums[i],mx);
            nums[i]=(__gcd(mx,nums[i]));
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int r=nums.size()-1;
        for(int i=0;i<nums.size()/2;i++){
            ans+=__gcd(nums[i],nums[r]);
            r--;
        }
        return ans;
    }
};