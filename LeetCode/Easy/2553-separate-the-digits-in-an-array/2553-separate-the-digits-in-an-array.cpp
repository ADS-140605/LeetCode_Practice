class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            vector<int> temp;
            while(num>0){
                temp.push_back(num%10);
                num/=10;
            }
            reverse(temp.begin(),temp.end());
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};