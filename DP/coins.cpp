#include<bits/stdc++.h>
using namespace std;
double dp[3005][3005];
double f(vector<double>p,int i,int x){
    if(x==0) return 1;
    if(x!=0 && i==-1) return 0;
    if(dp[i][x]>-0.9) return dp[i][x];
    return dp[i][x] = (p[i]*f(p,i-1,x-1)) + ((1-p[i])*f(p,i-1,x));
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<double>p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    int x = (n+1)/2;
    cout<<f(p,n-1,x);

}