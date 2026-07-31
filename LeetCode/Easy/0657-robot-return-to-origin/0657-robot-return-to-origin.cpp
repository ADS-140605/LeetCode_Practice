class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,l=0,u=0,d=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L') l++;
            if(moves[i]=='R') r++;
            if(moves[i]=='U') u++;
            if(moves[i]=='D') d++;
        }
        return (r==l)&&(u==d);
    }
};