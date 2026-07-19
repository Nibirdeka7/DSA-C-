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
    for(int i = 1;i < n; i++) arr[i] = arr[i]^arr[i-1];
    ll exor = arr[k-1];
    for(int i = k; i < n; i++){
        ll ans = arr[i]^arr[i-k];
        exor ^= ans;
    }
    cout << exor << endl;
}