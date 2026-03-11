//Write a program to apply binary search in array sorted in decreasing order.
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={7,6,5,3,2,0};
    int tgt=2;
    int lo=0,hi=a.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]==tgt){
            cout<<mid;
            break;
        }
        else if(a[mid]>tgt) lo=mid+1;
        else hi=mid-1;
    }

}