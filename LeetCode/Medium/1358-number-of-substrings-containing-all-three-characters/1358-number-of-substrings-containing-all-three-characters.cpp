class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq={0,0,0};
        int l=0,r=0;
        int count=0;
        while(r<s.length()){
            if (s[r]=='a') freq[0]++;
            if (s[r]=='b') freq[1]++;
            if (s[r]=='c') freq[2]++;
            while(freq[0]>=1 &&freq[1]>=1 && freq[2]>=1){
                if (s[l]=='a') freq[0]--;
                if (s[l]=='b') freq[1]--;
                if (s[l]=='c') freq[2]--;
                l++;
            }
            count+=l;
            r++;
        }
        return count;
    }
};