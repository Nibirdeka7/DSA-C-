#include<bits/stdc++.h>
using namespace std;
void triangle(vector<int>&v,int n){
    if(n==0) return;
    vector<int>tmp(n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
        if(i!=0){
            tmp[i-1]=v[i]+v[i-1];
        }
    }
    cout<<endl;
    triangle(tmp,n-1);
}
int main(){
    vector<int>v={5,4,3,2,1};
    int n=v.size();
    triangle(v,n);
}