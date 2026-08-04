class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=1,j;
        while(i<n){
            j=nums[i-1];
            while(nums[i]-j!=1){
                ans.push_back(++j);
            }
            i++;
        }
        return ans;
    }
};