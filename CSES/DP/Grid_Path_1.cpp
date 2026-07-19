#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
    int n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    if (mat[0][0] == '*') {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    cout << dp[n - 1][n - 1] % mod;
    return 0;
}
