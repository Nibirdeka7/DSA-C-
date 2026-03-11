#include<bits/stdc++.h>
using namespace std;
int main(){
    // arr = { 10, 20, -4, 6, 18, 24, 105, 118} k=3] 
    priority_queue<int>pq; // max heap (by default)
    int arr []=  { 10, 20, -4, 6, 18, 24, 105, 118} ;
    int k=3;
    int n=sizeof(arr)/4;
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<pq.top();
}