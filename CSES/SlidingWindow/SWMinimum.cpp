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
    deque<int>dq;
    ll exor = 0;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        while(!dq.empty() && dq.back() > num) dq.pop_back();
        dq.push_back(num);
        if(i >= k && arr[i-k] == dq.front()) dq.pop_front();
        if(i >= k-1) exor ^= dq.front();
    }
    cout << exor << endl;
}