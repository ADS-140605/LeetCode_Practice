class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') pos.push_back(i);
        }
        
        if(pos.size()<k) return "";
        
        string ans="";
        int len=1e9;
        
        for(int i=0;i+k-1<pos.size();i++){
            int l=pos[i],r=pos[i+k-1];
            string cur=s.substr(l,r-l+1);
            
            if(cur.size()<len){
                len=cur.size();
                ans=cur;
            }
            else if(cur.size()==len && cur<ans){
                ans=cur;
            }
        }
        
        return ans;
    }
};