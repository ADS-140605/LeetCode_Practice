class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int> freq(26,0);
        for(char x:s) freq[x-'a']++;
        string ans="";
        
        for(int i=0;i<t.size();i++){
            int x=t[i]-'a';
            if(freq[x]){
                ans+=t[i];
                freq[x]--;
                continue;
            }
            for(int j=x+1;j<26;j++){
                if(freq[j]){
                    ans+=char('a'+j);
                    freq[j]--;
                    for(int k=0;k<26;k++){
                        ans+=string(freq[k],char('a'+k));
                    }
                    return ans;
                }
            }
            break;
        }
        
        while(!ans.empty()){
            int p=ans.back()-'a';
            ans.pop_back();
            freq[p]++;
            for(int j=p+1;j<26;j++){
                if(freq[j]){
                    ans+=char('a'+j);
                    freq[j]--;
                    for(int k=0;k<26;k++){
                        ans+=string(freq[k],char('a'+k));
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};