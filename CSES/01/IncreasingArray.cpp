#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    long long ans = 0;
    for(int i = 0;i < n; i++) cin >> a[i];
    long long maxi = a[0];
    for(int i = 1;i < n; i++){
        if(a[i] < maxi){
            ans += maxi-a[i];
        }
        maxi = max(maxi, a[i]);
        // cout << ans << " " << maxi << endl; 
    }
    cout << ans;

}