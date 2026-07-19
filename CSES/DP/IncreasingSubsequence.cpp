#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    reverse(nums.begin(), nums.end());
    int ans = 0;
    // vector<int>dp(n+1, 1);
    // for(int i = 0; i < n; i++){
    //     for(int prev = 0; prev < i; prev++){
    //         if(nums[i] > nums[prev] && 1 + dp[prev] > dp[i]){
    //             dp[i] = 1 + dp[prev];
    //         }
    //     }
    //     if(dp[i] > ans){
    //         ans = dp[i];
    //     }
    // }
    vector<int>tmp;
    tmp.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        if(nums[i] > tmp.back()){
            tmp.push_back(nums[i]);
        } else {
            int ind = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
            tmp[ind] = nums[i];
        }
    }
    cout << tmp.size() << endl;
}