class Solution {
public:
    string removeDuplicates(string s) {
        if (s.empty()) return "";
        string ans ="";
        int i=s.length()-1;
        stack<char> st;
        st.push(s[i]);
        i--;
        while(i>=0){
            char crr=s[i];
            if(!st.empty()&&(char)st.top()==crr){
                st.pop();
            }else{
                st.push(crr);
            }
            i--;
        }
        while(!st.empty()){
            char x=st.top();st.pop();
            ans.push_back(x);
        }
        return ans;
    }
};