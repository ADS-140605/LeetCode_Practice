class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(const auto& x:s) mp[x]++;
        vector<vector<char>> bucket(n+1);
        for(const auto& [k,v]:mp){
            bucket[v].push_back(k);
        }
        string res;
        for(int count=n;count>=1;count--){
            for(const auto& k:bucket[count]){
                res+=string(count,k);
            }
        }
        return res;
    }
};