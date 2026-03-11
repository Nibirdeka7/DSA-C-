// Given a sorted binary array, efficiently count the total number of 1’s in it.
// Input 1 : a = [0,0,0,0,1,1]
// Output 1: 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={0,0,0,1,1,1,1,1,2,3,4,5};
    int l1=lower_bound(arr.begin(),arr.end(),1)-arr.begin();
    int l2=upper_bound(arr.begin(),arr.end(),1)-arr.begin();
    cout<< l2-l1;
}