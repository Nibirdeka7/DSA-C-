#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        totalSum += a[i];
    }
    vector<bool> prev(totalSum + 1, false);
    prev[0] = true;
    for (int i = 0; i < n; i++){
        vector<bool> curr(totalSum + 1, false);
        curr[0] = true;
        for (int sum = 1; sum <= totalSum; sum++){
            bool notPick = prev[sum];
            bool pick = false;
            if (sum >= a[i]) {
                pick = prev[sum - a[i]];
            }
            curr[sum] = pick || notPick;
        }
        prev = curr;
    }
    vector<int> ans;
    for (int sum = 1; sum <= totalSum; sum++) {
        if (prev[sum]) {
            ans.push_back(sum);
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}