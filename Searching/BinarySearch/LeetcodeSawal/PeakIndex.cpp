#include<bits/stdc++.h>
using namespace std;
int findPeak(vector<int>&arr){
    int n=arr.size();
    int l=0,h=n-1;
    while(l<=h){
    int mid=l+(h-l)/2;
    if((arr[mid]>arr[mid+1]) && (arr[mid]>arr[mid-1]))
    return mid;
    else if(arr[mid]>arr[mid+1]) h=mid-1;
    else l=mid+1;
    }
}
int main(){
    vector<int>arr={1,2,5,3,2,1};
    int res=findPeak(arr);
    cout<< res;
}