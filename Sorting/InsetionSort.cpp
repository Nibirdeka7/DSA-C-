#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,3,1,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<=n;i++){
        int idx=i;
        while(idx>=1){
             if(arr[idx]>=arr[idx-1]) break;
            else
            swap(arr[idx],arr[idx-1]);
            idx--;
            
          
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}