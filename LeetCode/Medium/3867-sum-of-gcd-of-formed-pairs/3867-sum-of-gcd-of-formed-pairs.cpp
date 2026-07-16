class Solution {
public:
    using ll=long long;
    long long gcdSum(vector<int>& nums) {
        vector<int> p;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx= max(nums[i],mx);
            p.push_back(gcd(mx,nums[i]));
        }
        sort(p.begin(),p.end(),[](ll a,ll b){return a>b;});
        long long ans=0;
        int r=p.size()-1;
        for(int i=0;i<p.size()/2;i++){
            ans+=__gcd(p[i],p[r]);
            r--;
        }
        return ans;
    }
};