#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<long long,int>mp;
    for(int num : a){
        mp[num]++;
    }
    cout << mp.size();
}