#include<bits/stdc++.h>
using namespace std;
int lastOccur(vector<int>&a,int tgt){
    int l=0,h=a.size()-1,ans=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(a[mid]<=tgt){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
        
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    int tgt;
    cin>>tgt;
    int ls=lastOccur(arr,tgt);
    cout<<ls;
}