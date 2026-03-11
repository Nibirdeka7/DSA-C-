#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[8]={1,3,-1,-3,5,3,6,7};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>ans;
    
    for(int i=0;i<n-k+1;i++){
        int max=INT_MIN;
        int lo=i;
        int hi=i+k-1;
        while(lo<=hi){
            if(arr[lo]>max) max=arr[lo];
            lo++;
        }
        ans.push_back(max);
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}