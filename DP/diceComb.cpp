#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll f(int n, vector<ll>&dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int sum=0;
    for(int i=1;i<=6;i++){
        if(n-i<0) break;
        sum = (sum % mod + f(n-i,dp) % mod)%mod;
    }
    return  dp[n]=sum%mod;
}

int main(){
    int n;
    cin>>n;
    vector<ll>dp(n+1,-1);
    cout<<f(n,dp)<<endl;
}