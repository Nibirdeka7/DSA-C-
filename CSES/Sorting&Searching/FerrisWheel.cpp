#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = 0, h = n-1;
    int ans =0;
    while(l <= h){
        if(a[l]+a[h] <= x){
            ans++;
            l++;
            h--;
        } else {
            h--;
            ans++;
        }
    }
    cout << ans;
}