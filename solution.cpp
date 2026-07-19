#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(vector<int>& a, int m, ll mid) {
    int workers = 1;
    ll cur = 0;
    for (int x : a) {
        if (x > mid) return false; 
        if (cur + x > mid) {
            workers++;
            cur = x;
        } else {
            cur += x;
        }
    }
    return workers <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        ll sum = 0, maxi = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            maxi = max(maxi, (ll)a[i]);
        }
        ll l = maxi, r = sum, ans = sum;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (f(a, m, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}