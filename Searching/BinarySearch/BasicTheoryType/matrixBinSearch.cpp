#include<bits/stdc++.h>
using namespace std;
bool searchMat(vector<vector<int>>&a,int tgt){
    int m=a[0].size();
    int n=a.size();
    int lo=0;
    int hi=m*n-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int row=mid/m;
        int col=mid%m;
        if(a[row][col]==tgt) return true;
        else if(a[row][col]<tgt) lo=mid+1;
        else hi=mid-1;
    }
    return false;
}
int main(){
    vector<vector<int>>a={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int tgt=30;
    bool res= searchMat(a,tgt);
    cout<<res;
}