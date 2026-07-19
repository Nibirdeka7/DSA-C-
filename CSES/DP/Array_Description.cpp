#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define INF 1000000000000
using namespace std;

ll getans(vector<ll> &arr, ll N, ll M, vector<vector<ll>> &dp)
{
     for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            if (arr[i] == 0)
            {
                for (int val = 1; val <= M; val++)
                    dp[i][val] = 1;
            }
            else
            {
                dp[i][arr[i]] = 1;
            }
        }
        else
        {
            if (arr[i] == 0)
            {
                for (int val = 1; val <= M; val++)
                {
                    dp[i][val] = (dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % mod;
                }
            }
            else
            {
                dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int val = 1; val <= M; val++)
    {
        ans = (ans + dp[N - 1][val]) % mod;
    }
    return ans;
}
int main()
{

    ll N, M;
    cin >> N >> M;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    vector<vector<ll>> dp(N, vector<ll>(M + 2, 0));
    cout << getans(arr, N, M, dp) << endl;
}