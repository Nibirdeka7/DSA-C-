
#include<bits/stdc++.h>
using namespace std;
int main(){
    // in TC: O(n)
     int arr[]={0,1,2,3,4,8,9,55};
     int n=sizeof(arr)/sizeof(arr[0]);
    // int m;
    // for(int i=0;i<n;i++){
        
    //     if(i!=arr[i]){
    //     cout<<i;
    //     break;
    //     }
    // }
    // TC: O(log(n));
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid) lo=mid+1;
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans;
}