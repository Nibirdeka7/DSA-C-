// brute force method
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,1,8,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int invCnt=0;
    for(int i=0;i<n-1;i++){
       // int a=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) invCnt++;
        }
    }
    cout<<invCnt;
}