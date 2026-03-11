#include<bits/stdc++.h>
using namespace std;
bool check(int mid,vector<int>& weights, int days){
    int n=weights.size();
    int m = mid;
    int count = 1;
    for(int i=0; i<n; i++){
        if(m>=weights[i]){
            m-=weights[i];
        }
        else{
            count++;
            m = mid;
            m-=weights[i];
        }
    }
    if(count>days) return false;
    else return true;
}
int minCap(vector<int>&weigh,int days){
    int i;
    int max=-1;
    int sum=0;
    for(i=0;i<weigh.size();i++){
        if(weigh[i]>max) max=weigh[i];
        sum+=weigh[i];
    }
    int lo=max;
    int hi=sum;
    int minCapacity=sum;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid,weigh,days)){
            minCapacity = mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return minCapacity;
}
int main(){
     vector<int>weigh={3,2,2,4,1,4};
     int days=3;
     cout<< minCap(weigh,days);
}