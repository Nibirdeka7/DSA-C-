#include<bits/stdc++.h>
using namespace std;
// Array must be sorted (ascending or descending)
// T.C = O(log(N)); Worst case
// T.C = O(1); Best case
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
    vector<int> nums={-1,3,5,7,9};
    int target=7;
    int n=nums.size()-1;
    int res=binSearch(nums,0,n,target);
    cout<< res;
}