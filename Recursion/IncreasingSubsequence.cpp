#include<bits/stdc++.h>
using namespace std;
void subset(int arr[],int n,int idx,vector<int> v,int k ){
    if(idx==n){
        if(v.size()==k){
            for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
            cout<<endl;          
        }
        return;
    }
    if(v.size()+(n-idx)<k) return;
    int a=arr[idx];
    subset(arr,n,idx+1,v,k);
    v.push_back(a);
    subset(arr,n,idx+1,v,k);
}
int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    subset(arr,n,0,v,3);
}