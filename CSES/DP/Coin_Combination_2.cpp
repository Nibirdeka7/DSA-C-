#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ll n, val;
    cin >> n >> val;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    vector<ll> dp(val + 1, 0);
    dp[0] = 1; 
    for (ll i = 0; i < n; i++) {      
        for (ll j = coins[i]; j <= val; j++) { 
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }
    cout << dp[val];
    return 0;
}