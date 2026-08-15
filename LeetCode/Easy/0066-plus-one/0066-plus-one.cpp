class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n=d.size(); 
        // int t=d[n-1]+1,c;
        // c=t/10;
        // d[n-1]=t%10;
        // if(n==1){
        //     d={c,d[n-1]};
        //     return d;
        // }
        // for(int i=n-2;i>=0;i--){
        //     t=d[i]+c;
        //     c=t/10;
        //     d[i]=t%10;
        // }
        // if (c==1){
        //     d.insert(d.begin(),1);
        // }
        // return d;
        for(int i=n-1;i>=0;i--){
            if(d[i]<9){
                d[i]++;
                return d;
            }
            d[i]=0;
        }
        d.insert(d.begin(),1);
        return d;
    }
};