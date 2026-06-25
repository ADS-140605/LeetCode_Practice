class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int max_d=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') depth++;
            if(s[i]==')') depth--;
            max_d=max(max_d,depth);
        }
        return max_d;
    }
};