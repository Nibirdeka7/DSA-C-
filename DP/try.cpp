#include<bits/stdc++.h>
using namespace std;
int f(string a, string b, int i, int j,vector<vector<int>>&dp){
    if(i>a.size()-1 || j>b.size()-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]=1+f(a,b,i+1,j+1,dp);
    else return dp[i][j]= max(f(a,b,i+1,j,dp), f(a,b,i,j+1,dp));
}
int main(){
        string s,p;
        cin>>s>>p;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
            return f(t,p,0,0,dp);
        }
    }