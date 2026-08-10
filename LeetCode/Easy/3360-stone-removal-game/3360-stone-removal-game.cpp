class Solution {
public:
    bool canAliceWin(int n) {
        int k=10;
        bool a=true;
        while(n>=k){
            n-=k;
            k--;
            a=!a;
        }
        return !a;
    }
};