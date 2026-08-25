class Solution {
public:
    int missingMultiple(vector<int>& nu, int k) {
        sort(nu.begin(),nu.end());
        int n =nu.size();
        int c=1;
        for(int i=0;i<n;i++){
            if(k*c==nu[i]) c++;
        }
        return c*k;
    }
};