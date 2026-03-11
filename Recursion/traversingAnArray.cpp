#include<bits/stdc++.h>
using namespace std;
void display(int n,int arr[],int idx){
    if(idx>=n) return;
    cout<<arr[idx]<<" ";
    display(n,arr,idx+1);
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(n,arr,0);
}