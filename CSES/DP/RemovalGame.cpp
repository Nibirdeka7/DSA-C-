#include<bits/stdc++.h>
using namespace std;

long long f(int l, int r,
            vector<long long>& a,
            vector<vector<long long>>& dp){

    if(l > r) return 0;
    if(l == r) return a[l];

    if(dp[l][r] != -1)
        return dp[l][r];

    long long takeLeft =
        a[l] +
        min(
            f(l+2,r,a,dp),
            f(l+1,r-1,a,dp)
        );

    long long takeRight =
        a[r] +
        min(
            f(l+1,r-1,a,dp),
            f(l,r-2,a,dp)
        );

    return dp[l][r] =
        max(takeLeft,takeRight);
}

int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}