#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define ll long long
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n)
{
    return power(n, MOD - 2);
}
void solve()
{
    int m;
    cin >> m;
    if (m == 0)
    {
        cout << "\n";
        return;
    }
    vector<ll> fact(m + 1);
    vector<ll> invfact(m + 1);
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[m] = modInverse(fact[m]);
    for (int i = m - 1; i >= 1; --i)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
    vector<ll> ans(m + 1, 0);
    for (int k = 1; k <= m / 2; ++k)
    {
        int lim = (m / k) - 1;
        for (int n = 1; n <= lim; ++n)
        {
            ll a = m - (ll)(n + 1) * k + n;
            ll b = m - (ll)(n + 1) * k;
            ll term = (fact[a] * invfact[b]) % MOD;
            ans[n] = (ans[n] + term) % MOD;
        }
    }
    ans[m] = 0;
    for (int i = 1; i <= m; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}