#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int bitCnt[32];

void add(ll x, ll &currOr){
    while(x){
        int bit = __builtin_ctzll(x);   // lowest set bit
        bitCnt[bit]++;
        currOr |= (1LL << bit);
        x &= (x - 1);                   // remove lowest set bit
    }
}

void removeNum(ll x, ll &currOr){
    while(x){
        int bit = __builtin_ctzll(x);
        bitCnt[bit]--;

        if(bitCnt[bit] == 0){
            currOr &= ~(1LL << bit);
        }

        x &= (x - 1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin>>n>>k;

    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    queue<ll> window;

    ll currOr = 0;
    ll ans = 0;

    // build first window
    for(int i=0;i<k;i++){

        window.push(x);
        add(x,currOr);

        x = (a*x+b)%c;
    }

    ans ^= currOr;

    // remaining windows
    for(ll i=k;i<n;i++){

        ll old = window.front();
        window.pop();

        removeNum(old,currOr);

        window.push(x);
        add(x,currOr);

        ans ^= currOr;

        x = (a*x+b)%c;
    }

    cout<<ans<<"\n";
}