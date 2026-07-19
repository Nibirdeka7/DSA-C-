#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i= 0; i < n; i++) cin >> nums[i];
    vector<int>dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){
                dp[i] += 1 + dp[prev];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += dp[i];
        if(dp[i] > 1) ans++;
    }
    
    cout << ans%(1000000007) << endl;
}