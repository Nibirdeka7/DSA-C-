
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int lo=0;
    int hi=n;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if((mid*mid)==n){ 
            ans=mid;
            break;
        }
        else if((mid*mid)>n) hi=mid-1;
        else lo=mid+1;
    }
    cout<<ans;

}