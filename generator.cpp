#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll uid(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

int main() {
    freopen("input_max_n.txt", "w", stdout);

    // n = 2*10^5, m = 1 means one worker takes all bags
    // answer must be sum(a[i]) — tests upper bound of binary search
    int T = 1;
    cout << T << "\n";

    int n = 200000;
    int m = 1; // only 1 worker, forced to take everything
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << uid(1, 1000000000LL);
        if (i + 1 < n) cout << " ";
    }
    cout << "\n";

    cerr << "Gen4 done: n=" << n << " m=1, answer=sum\n";
    return 0;
}