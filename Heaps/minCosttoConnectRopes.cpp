#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,7,4,1,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cost=0;
    while(pq.size()>=1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        int p = x+y;
        cost+=p;
        pq.push(p);
    }
    cout<<cost;
}