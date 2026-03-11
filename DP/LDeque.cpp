// Taro and Jiro will play the following game against each other.

// Initially, they are given a sequence 
// a=(a1,a2,…,aN). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
// Remove the element at the beginning or the end of 
// a. The player earns x points, where x is the removed element.Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize 
// X−Y, while Jiro tries to minimize X−Y.
// Assuming that the two players play optimally, find the resulting value of 
// X−Y.
#include<bits/stdc++.h>
using namespace std;
int f(int i, int j,vector<int>p, vector<vector<int>>&dp){
    if(i==j) return p[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = max(p[i]-f(i+1,j,p,dp),p[j]-f(i,j-1,p,dp));
}
int main(){
    int n;
    cin>>n;
    vector<int>p(n);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<n;i++) cin>>p[i];
    cout<<f(0,n-1,p,dp);
}