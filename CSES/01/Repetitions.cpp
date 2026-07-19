#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int>pref(n, 0);
    pref[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            pref[i] = 1 + pref[i-1];
        } else {
            pref[i] = 1;
        }
        ans = max(ans, pref[i]);
    }
    cout << ans;
}