class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int a=0;
        bool zero=true;
        int n=nums.size();
        for(auto x:nums){
            if(x!=0) zero=false;
            a^=x;
        }
        if(zero) return 0;
        if (a!=0) return n;
        return n-1;
    }
};