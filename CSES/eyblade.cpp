#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll t, ll k, vector<ll>a){
    ll energy = 0;
        for (int i = 1; i <= a.size(); i++) {
            if (__gcd((ll)i, t) == 1) {
                energy += t / a[i - 1];
                if (energy >= k) return true;
            }
        }
        return energy >= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll k;
    cin >> k;
    ll left = 1, right = 1e18;
    ll ans = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid, k, a)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}