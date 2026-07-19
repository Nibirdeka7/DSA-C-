#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll,ll>mp;
    for(int i = 0; i < k; i++) mp[a[i]]++;
    vector<ll>ans;
    ans.push_back(mp.size());
    for(int i = k; i < n; i++){
        mp[a[i]]++;
        mp[a[i-k]]--;
        if(mp[a[i-k]] == 0) mp.erase(a[i-k]);
        ans.push_back(mp.size());
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}