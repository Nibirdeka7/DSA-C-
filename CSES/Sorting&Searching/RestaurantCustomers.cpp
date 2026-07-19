#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> events;

    while(n--) {
        int a, b;
        cin >> a >> b;

        events.push_back({a, 1});   // arrival
        events.push_back({b, -1});  // leaving
    }

    sort(events.begin(), events.end());

    int cur = 0;
    int ans = 0;

    for(auto it : events) {
        cur += it.second;
        ans = max(ans, cur);
    }

    cout << ans;
}