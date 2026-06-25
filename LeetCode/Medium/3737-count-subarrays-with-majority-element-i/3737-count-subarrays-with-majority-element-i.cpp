class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        //n<=1000 O(n^2) valid
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=i;j<nums.size();j++){
                if (nums[j]==target) count++;
                int length=j-i+1;
                if(count*2>length) ans++;
            }
        }
        return ans;
    }
};