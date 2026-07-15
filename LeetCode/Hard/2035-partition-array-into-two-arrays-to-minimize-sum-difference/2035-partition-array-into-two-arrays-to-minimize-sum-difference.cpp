class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total_len=nums.size();
        int n=total_len/2;
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        int target=total_sum/2;
        vector<vector<int>> left_sums(n+1);
        vector<vector<int>> right_sums(n+1);
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            int count=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=nums[j];
                    count++;
                }
            }
            left_sums[count].push_back(sum);
        }
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            int count=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=nums[n+j];
                    count++;
                }
            }
            right_sums[count].push_back(sum);
        }
        for(int i=0;i<=n;i++){
            sort(right_sums[i].begin(),right_sums[i].end());
        }
        int m=1e9;
        for(int k=0;k<=n;k++){
            int right_count=n-k;
            for(int i=0;i<left_sums[k].size();i++){
                int l_sum=left_sums[k][i];
                int search_target=target-l_sum;
                auto it=lower_bound(right_sums[right_count].begin(),right_sums[right_count].end(),search_target);
                if(it!=right_sums[right_count].end()){
                    int current_sum=l_sum+*it;
                    m=min(m,abs(2*current_sum-total_sum));
                }
                if(it!=right_sums[right_count].begin()){
                    int current_sum=l_sum+*prev(it);
                    m=min(m,abs(2*current_sum-total_sum));
                }
            }
        }
        return m;
    }
};