// with duplicate elements
#include<bits/stdc++.h>
using namespace std;
void subset(vector<int> &arr,int n,int idx,vector<int> v ,bool flag){
    if(idx==n){
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
       // cout<<endl;
        return;
    }
    int a=arr[idx];
    if(arr.size()==1){
        if(flag==true)  subset(arr,n,idx+1,v,true);
        v.push_back(a);
         subset(arr,n,idx+1,v,false);
    }
    int b=arr[idx+1];
    if(a==b){
        if(flag==true)  subset(arr,n,idx+1,v,true);
        v.push_back(a);
         subset(arr,n,idx+1,v,false);
    }
    else{
        if(flag==true)  subset(arr,n,idx+1,v,true);
        v.push_back(a);
         subset(arr,n,idx+1,v,true);
    }
}
int main(){
    vector<int> arr={1,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr.begin(),arr.end());
    vector<int>v;
    subset(arr,n,0,v,true);
}