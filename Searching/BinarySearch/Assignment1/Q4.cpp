// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n]
// inclusive in sorted order.
// There is only one repeated number in nums, return this repeated number.
// Input 1: arr[] = {1,2,3,3,4}
// Output 1: 3
// Input 2: arr[] = {1,2,2,3,4,5}
// Output 2: 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,2,3,3,4};
    int i,l1,l2; 
    for(i=0; i<arr.size();i++){
       l1= lower_bound(arr.begin(),arr.end(),arr[i])- arr.begin();
      l2= upper_bound(arr.begin(),arr.end(),arr[i])- arr.begin();
    if(arr[l1]==arr[l2]) 
    cout<< arr[l1];
    //else cout<< -1;
    }

}