#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={5,4,3,2,1};
    int tgt=4;
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==tgt){ 
            cout<<mid;
            break;
            }
        else if(v[mid]<tgt) hi=mid-1;
        else lo=mid+1;
    }
}