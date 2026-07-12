class Solution {
public:
    string removeDuplicates(string s) {
        if (s.empty()) return "";
        string ans ="";
        ans.reserve(s.size());
        for(char x:s | views::reverse){
            if(!ans.empty() && ans.back()==x){
                ans.pop_back();
            }else{
                ans.push_back(x);
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};