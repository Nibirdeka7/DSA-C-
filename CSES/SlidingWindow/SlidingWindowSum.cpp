#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for(int i = 1; i < n; i++) {
        arr[i] = (1LL * a * arr[i-1] + b) % c;
    }
    ll base = 0;
    for(int i = 0; i < k; i++) base += arr[i];
    ll exor = base;
    for(int i = k; i < n; i++) {
        ll sm = base + arr[i] - arr[i-k];
        exor ^= sm;
        base = sm;   
    }
     cout << exor << endl;
}