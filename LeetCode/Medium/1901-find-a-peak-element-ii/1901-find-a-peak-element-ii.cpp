class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
     int n=mat.size(),m=mat[0].size();
     int low=0,high=m-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        int temp=-1,maxrowidx=-1;//max value in the mid column
        for(int i=0;i<n;i++){
            if(temp<mat[i][mid]){
                temp=mat[i][mid];
                maxrowidx=i;
            }
        }
        int l=(mid-1>=0)?mat[maxrowidx][mid-1]:-1;
        int r=(mid+1<m)?mat[maxrowidx][mid+1]:-1;
        if(mat[maxrowidx][mid]>l && mat[maxrowidx][mid]>r) return {maxrowidx,mid};
        else if(mat[maxrowidx][mid]<l){
            high =mid-1;
        }else{
            low=mid+1;
        }
     }
     return {-1,-1};
    }
};