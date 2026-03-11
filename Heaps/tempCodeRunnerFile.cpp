#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,1,3,89,56,0,7};
    priority_queue<int>pq;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int i=n-1;
    while(pq.size()!=0){
        arr[i]=pq.top();
        pq.pop();
        i--;
    }
    for(int j=0;j<n;j++) cout<<arr[j]<<" ";
}