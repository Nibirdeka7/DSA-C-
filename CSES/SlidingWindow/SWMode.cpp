#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<ll, int>mp;
    set<pair<int, ll>>st;
    for(int i = 0; i < k; i++) mp[a[i]]++;
    for(auto x : mp) st.insert({x.second, -x.first});
    vector<int>res;
    int mode = -st.rbegin()->second;
    res.push_back(mode);
    for(int i = k; i < n; i++){
        int out = a[i-k];
        int in = a[i];

        st.erase({mp[out], -out});
        mp[out]--;
        if(mp[out] > 0) st.insert({mp[out], -out});
        else mp.erase(out);

        if(mp.count(in)) st.erase({mp[in], -in});
        mp[in]++;

        st.insert({mp[in], -in});
        mode = -st.rbegin()->second;
        res.push_back(mode);
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";

}