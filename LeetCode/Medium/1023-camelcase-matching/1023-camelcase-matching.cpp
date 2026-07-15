class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n=queries.size(),m=pattern.length();
        int j=0;
        vector<bool> ans;
        for(int i=0;i<n;i++){
            bool t=true;
            for(int k=0;k<queries[i].size();k++){
                if(j<m && queries[i][k]==pattern[j]){
                    j++;
                }
                else if(queries[i][k]>='A' && queries[i][k]<='Z'){
                    t=false;
                    break;
                }
            }
            ans.push_back(t && j==m);
            j=0;
        }
        return ans;
    }
};