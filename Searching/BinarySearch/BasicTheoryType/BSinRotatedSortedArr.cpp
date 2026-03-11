
#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&nums,int target){
    int n=nums.size();
    int lo=0;
    int hi=n-1;
    int pivot=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){ 
        pivot=mid+1;
        break;
        }
        else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
        pivot=mid;
        break;
        }
        else if(nums[mid]>nums[hi]) lo=mid+1;
        else hi=mid-1;
    }
    if(target>=nums[0] && target<=nums[pivot-1]){
    lo=0;
    hi=pivot-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) hi=mid-1;
        else lo=mid+1;
    }
    }
    else{
    lo=pivot;
    hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) hi=mid-1;
        else lo=mid+1;
    }
    }
    return -1;
}
int main(){
    vector<int>v={4,5,6,7,0,1,2};
    int tgt=0;
    cout<<search(v,tgt);
}