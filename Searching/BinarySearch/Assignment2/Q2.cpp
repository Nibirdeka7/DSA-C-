// You have a sorted array of infinite numbers, how would you search an element in the array?
#include<bits/stdc++.h>
using namespace std;
int binSearch(vector<int>&nums,int low,int high,int target){
    while(low<=high){
        int mid=(low+high)/2;
        // int mid=low+(high-low)/2;
        if(nums[mid]==target)
        return mid;
        if(nums[mid]<target)
        low=mid+1;
        if(nums[mid]>target)
        high=mid-1;
    }
    return -1;
}
int main(){
    vector<int>a={3, 5, 7, 9, 10, 90, 100, 130, 
                               140, 160, 170};
    int tgt;
    cin>>tgt;
    int lo=0;
    int hi=1;
    int val=a[0];
    while(val<tgt){
        lo=hi;
        hi=2*hi;
        val=a[hi];
    }
    cout<<binSearch(a,lo,hi,tgt);

}