#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=9;
    int k;
    cin>>k;
    int maxSum=INT_MIN;
    int prevSum=0;
    for(int i=0;i<k;i++)
    prevSum+=arr[i];
    int idx=-1;
    int i=1,j=k;
    while(j<n){
        int curSum=prevSum+arr[j]-arr[i-1];
        if(maxSum<curSum) {
            maxSum=curSum;
            idx=i;
        }
        prevSum=curSum;
        i++;
        j++;
    }
    cout<<maxSum<<" "<<idx;
}