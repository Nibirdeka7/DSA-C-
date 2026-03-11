// Given a sorted array of n elements and a target ‘x’. Find the last occurrence of ‘x’ in the array. If ‘x’
// does not exist return -1.
// Input 1: arr[] = {1,2,3,3,4,4,4,5} , x = 4
// Output 1: 6
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={1,2,3,3,4,4,4,4,4,4,4,5};
    int x=4;
    int res=  upper_bound(arr.begin(),arr.end(),x) - arr.begin();
    cout<< res-1;
}