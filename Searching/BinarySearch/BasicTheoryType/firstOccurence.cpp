#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,4,4,4,4,6,6,6,7,8,8,99,99,99,99};
    int x=99;
    int lo=0;
    int hi=(sizeof(arr)/sizeof(arr[0]))-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
            if(arr[mid-1]==x)
            hi=mid-1;
            else{
            cout<< mid;
            break;
            }
        }
        else if(arr[mid]<x) lo=mid+1;
        else hi=mid-1;
    }
}