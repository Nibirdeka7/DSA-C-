#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,3,1,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
   vector<int>v(n,0);
   int idx;
   for(int i=0;i<n;i++){
       int min=INT_MAX;
    for(int j=0;j<n;j++){
        if(v[j]==1) continue;
        else if(min>arr[j]){
            min=arr[j];
            idx=j;
        }
    }
    v[idx]=1;
    arr[idx]=i;
   }
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
}