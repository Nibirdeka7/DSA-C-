//using recursion
#include<bits/stdc++.h>
using namespace std;
// Array must be sorted (ascending or descending)
// T.C = O(log(N)); Worst case
// T.C = O(1); Best case
// if the recursive call stack is considered then space complexity is O(log(N))
int binSearch(vector<int>&nums,int low,int high,int target){
    while(low<=high){
        int mid=(low+high)/2;
        // int mid=low+(high-low)/2;
        if(nums[mid]==target)
        return mid;
        if(nums[mid]<target)
        return binSearch(nums,mid+1,high,target);
        if(nums[mid]>target)
        return binSearch(nums,low,mid-1,target);
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