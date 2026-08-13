class Solution {
public:
    struct Node { int maxlen,suf,pre; char lc,rc; };
    vector<Node> seg;

    Node merge(const Node& L,const Node& R,int llen,int rlen) {
        Node res;
        res.lc= L.lc; res.rc=R.rc;
        res.pre = (L.pre==llen && L.rc==R.lc) ?L.pre+R.pre:L.pre;
        res.suf =(R.suf==rlen && L.rc==R.lc)? R.suf+L.suf:R.suf;
        res.maxlen = max({L.maxlen,R.maxlen, (L.rc ==R.lc)? L.suf+R.pre:0});
        return res;
    }

    void build(int i,int l,int r,string &s) {
        if(l==r) { seg[i]={1,1,1,s[l],s[l]}; return;}
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,s); 
        build(2*i+2,mid+1,r,s);
        seg[i]=merge(seg[2*i+1],seg[2*i+2],mid-l+1,r-mid);
    }

    void update(int i,int l,int r,int pos,char ch) {
        if(l==r) { seg[i]= {1,1,1,ch,ch}; return;}
        int mid=l+(r-l)/2;
        if(pos<=mid) update(2*i+1,l,mid,pos,ch);
        else update(2*i+2,mid+1,r,pos,ch);
        seg[i]=merge(seg[2*i+1],seg[2*i+2],mid-l+1,r-mid);
    }

    vector<int> longestRepeating(string s,string queryCharacters,vector<int>& queryIndices) {
        int n=s.size(),k=queryIndices.size();
        seg.resize(4*n);
        build(0,0,n-1,s);
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            update(0,0, n-1,queryIndices[i] ,queryCharacters[i]);
            ans[i]=seg[0].maxlen;
        }
        return ans;
    }
};