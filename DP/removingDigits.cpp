// cses problem set
#include<bits/stdc++.h>
using namespace std;
int f(int n, vector<int>&dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int sum=0;
    for(int i=1;i<=6;i++){
        if(n-i<0) break;
        sum += f(n-i,dp);
    }
    return  dp[n]=sum;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<f(n,dp)%1000000007<<endl;
}