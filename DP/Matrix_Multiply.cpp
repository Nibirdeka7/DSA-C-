#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int>&arr,  vector<vector<int>>&dp){
    if( i==j || i+1==j) return 0;
    int ans = INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i+1; k<j; k++){
        ans = min(ans, f(i,k,arr,dp)+f(k,j,arr,dp)+arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<f(0,n-1,arr,dp);
    //  bottom up solution / tabulation method;

    vector<vector<int>>dpp(n,vector<int>(n,0));
    for(int len = 3; len <= n-1; len++){
        for(int i = 0; i+len-1<n; i++){
            int j = i+len-1;
            dpp[i][j]=INT_MAX;
            for(int k=i+1; k<j; k++){
                dpp[i][j] = min(dpp[i][j], dpp[i][k]+dpp[k][j]+arr[i]*arr[k]*arr[j]);
            }
        }
    }
}