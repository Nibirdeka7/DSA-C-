#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,3,1,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int idx=0;
    for(int j=0;j<n-1;j++){
        int min=INT_MAX;
        for(int i=j;i<n;i++){
            if(arr[i]<min){ 
             min=arr[i];
            idx=i;
            }
        }
        swap(arr[j],arr[idx]);
    }
     for(int j=0;j<n;j++)
     cout<<arr[j];
}