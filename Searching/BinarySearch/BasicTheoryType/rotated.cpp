#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,5,6,0,0,1,2};
    int tgt=1;
    int lo=0;
    int hi=v.size()-1;
    int pivot=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            pivot=mid+1;
            break;
        }
        else if(v[mid]>v[hi]) lo=mid+1;
        else hi=mid-1;
    }
    cout<<pivot;
}