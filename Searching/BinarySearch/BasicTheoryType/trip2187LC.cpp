#include<bits/stdc++.h>
using namespace std;
bool check(long long mid,vector<int>&time,int totalTrips){
    int trips=0;
    int n=time.size();
    for(int i=0;i<n;i++){
        trips+=mid/(long long)time[i];
    }
    if(trips<(long long)totalTrips) return false;
    else return true;
}
long long minTime(vector<int>&time,int totalTrips ){
    int max=-1;
    int n=time.size();
    for(int i=0;i<n;i++){
        if(time[i]>max) max=time[i];
    }
    long long lo=1;
    long long hi=(long long)max*(long long)totalTrips;
    long long ans=-1;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        if(check(mid,time,totalTrips)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}
int main(){
    vector<int>time={1,2,3};
    int totalTrips=5;
    cout<<minTime(time,totalTrips);
}