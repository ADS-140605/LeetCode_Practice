class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return n;
        int bits=0;
        int temp=n;
        while(temp>0){
            bits++;
            temp>>=1;
        }
        return 1<<bits;
    }
};