#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    bool flag=false;
    int x=0;
    while(x<n){
        if(2*arr[x]==arr[n-1]){
            flag=true;
            break;
        }
        else x++;
    }
    if(flag) cout<<"Yes";
    else cout<<"No";

}