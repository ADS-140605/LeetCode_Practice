class Solution {
public:
    int largestInteger(vector<int>& nums,int k) {
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int i=n-1;i>=0;i--){
                if((i==0 || nums[i]!=nums[i-1]) &&
                   (i==n-1 || nums[i]!=nums[i+1]))
                    return nums[i];
            }
            return -1;
        }
        int a=nums[0],b=nums[n-1];
        for(int i=1;i<n-1;i++){
            if(nums[i]==a) a=-1;
            if(nums[i]==b) b=-1;
        }

        return (a==b)?-1:max(a,b);
    }
};