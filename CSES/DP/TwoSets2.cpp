#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INV2 = 500000004; // inverse of 2 modulo MOD

int main() {
    int n;
    cin >> n;

    long long sum = 1LL * n * (n + 1) / 2;

    if (sum & 1) {
        cout << 0 << '\n';
        return 0;
    }

    int target = sum / 2;

    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; num++) {
        for (int s = target; s >= num; s--) {
            dp[s] = (dp[s] + dp[s - num]) % MOD;
        }
    }

    cout << (dp[target] * INV2) % MOD << '\n';
}