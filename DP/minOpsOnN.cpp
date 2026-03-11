// n->n-1
// if n%2==0, n->n/2;
// if n%3==0, n->n/3;
// min ops to make n to 1;
#include<bits/stdc++.h>
using namespace std;
int f(int n, vector<int>&dp){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = 1 + min(f(n-1,dp), min((n % 2 == 0 ? f(n/2,dp) : INT_MAX), (n % 3 == 0 ? f(n/3,dp) : INT_MAX)));
}
int f2(int n){
    vector<int>tb(n+1);
    tb[1]=0;
    tb[2]=tb[3]=1;
    for(int i=4;i<=n;i++){
        tb[i] = 1 + min(tb[i-1], min((i % 2 == 0 ? tb[i/2] : INT_MAX), (i % 3 == 0 ? tb[i/3] : INT_MAX)));
    }
    return tb[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<f(n,dp)<<endl;
    cout<<f2(n);
}