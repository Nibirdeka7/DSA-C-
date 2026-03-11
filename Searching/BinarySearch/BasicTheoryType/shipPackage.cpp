#include<bits/stdc++.h>
using namespace std;
bool check(int mid,vector<int>&weigh,int days){
    int count=0;
    int m=mid;
    for(int i=0;i<weigh.size();i++){
        if(m>weigh[i]){
            m-=weigh[i];
        }
        else{
            count++;
            m=mid;
            m-=weigh[i];
        }
    }
    if(count>days) return false;
    else return true;
}
int ship(vector<int>&weigh,int days){
    int lo=-1;
    int hi=0;
    for(int i=0;i<weigh.size();i++){
        hi+=weigh[i];
        if(weigh[i]>lo) lo=weigh[i];
    }
    int minCap=hi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,weigh,days)){
            minCap=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return minCap;
}
int main(){
    vector<int>weigh={3,2,2,4,1,4};
    int days=3;
    cout<<ship(weigh,days);
}