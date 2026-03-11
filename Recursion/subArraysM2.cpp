#include <bits/stdc++.h>
using namespace std;
void subArray(vector<int>v,int arr[],int idx,int n){
    if(idx==n){
        for(int i=0;i<v.size();i++){
        cout<<v[i];
        }
        cout<<endl;
        return;
    }
    subArray(v,arr,idx+1,n);
    if(v.size()==0 || v[v.size()-1]==arr[idx-1]){
    v.push_back(arr[idx]);
    subArray(v,arr,idx+1,n);
    } 
}
int main(){
    int arr[]={1,2,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    subArray(v,arr,0,n);
}