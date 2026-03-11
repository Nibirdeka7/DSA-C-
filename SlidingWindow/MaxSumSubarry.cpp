#include<bits/stdc++.h>
using namespace std;
int maxSumSubArr(int arr[], int k,int n){
    int i=0,j=k-1,idx=-1;
    int ans=INT_MIN;
    for(int i=0;i<n-k+1;i++){
        int sum=0;
        for(int j=i;j<i+k;j++){
            sum+=arr[j];
        }
        ans=max(ans,sum);
        
    }
    cout<<"Sum= "<<ans;
    
}
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=9;
    int k;
    cin>>k;
    maxSumSubArr(arr,k,n);
}