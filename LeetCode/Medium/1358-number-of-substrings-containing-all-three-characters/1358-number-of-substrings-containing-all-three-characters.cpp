class Solution {
public:
    // int numberOfSubstrings(string s) {
    //     vector<int> freq={0,0,0};
    //     int l=0,r=0;
    //     int count=0;
    //     while(r<s.length()){
    //         if (s[r]=='a') freq[0]++;
    //         if (s[r]=='b') freq[1]++;
    //         if (s[r]=='c') freq[2]++;
    //         while(freq[0]>=1 &&freq[1]>=1 && freq[2]>=1){
    //             if (s[l]=='a') freq[0]--;
    //             if (s[l]=='b') freq[1]--;
    //             if (s[l]=='c') freq[2]--;
    //             l++;
    //         }
    //         count+=l;
    //         r++;
    //     }
    //     return count;
    // }
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}, left = 0, count = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            last[c - 'a'] = right;
            if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                count += min({last[0], last[1], last[2]}) + 1;
            }
        }

        return count;
    }
};