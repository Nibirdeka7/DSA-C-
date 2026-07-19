#include<bits/stdc++.h>
using namespace std;
int f(int i, int x, vector<int>&price, vector<int>&pages,vector<vector<int>>&dp){
    if(i == price.size()) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    int ans = f(i+1, x, price, pages,dp);
    if(x >= price[i]){
        ans = max(ans, pages[i]+f(i+1, x-price[i], price, pages,dp));
    }
    return dp[i][x] = ans;
}
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    // vector<vector<int>>dp(n, vector<int>(x+1,-1));
    // cout << f(0, x, price, pages,dp);
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
        dp[i][j] = dp[i-1][j];
        int left = j-price[i-1];
        if (left >= 0) {
        dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
        }
        }
    }
    cout << dp[n][x] << endl;
}