#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll f(ll val, vector<ll>& coins, vector<ll>& dp) {
    if (val == 0) return 1;
    if (dp[val] != -1) return dp[val];

    ll ans = 0;
    for (ll c : coins) {
        if (val - c >= 0)
            ans = (ans + f(val - c, coins, dp)) % mod;
    }

    return dp[val] = ans;
}

int main() {
    ll n, val;
    cin >> n >> val;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];

    vector<ll> dp(val + 1, -1);
    cout << f(val, coins, dp);
}
