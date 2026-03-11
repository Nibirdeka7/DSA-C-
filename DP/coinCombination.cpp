// cses problem set
#include<bits/stdc++.h>
using namespace std;
int f(int n,vector<int>coins, vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-2) return dp[n];
    int result = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(n-coins[i]<0) continue;
        result = min(result, f(n-coins[i],coins,dp));
    }
    if(result==INT_MAX) return dp[n]=INT_MAX;
    return  dp[n]=1 + result;
}
int main(){
    int c,n; 
    cin>>c>>n;
    vector<int>coins(c);
    for(int i=0;i<c;i++) cin>>coins[i];
    vector<int>dp(n+1,-2);
    
}