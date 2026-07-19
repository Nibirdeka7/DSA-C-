#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Project {
    ll start, end, reward;
};

vector<Project> projects;
vector<ll> dp;
vector<ll> starts;
int n;

ll f(int i) {
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];
    ll skip = f(i + 1);
    int next = upper_bound(starts.begin(), starts.end(), projects[i].end) - starts.begin();
    ll take = projects[i].reward + f(next);
    return dp[i] = max(skip, take);
}
int main() {
    cin >> n;
    projects.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    sort(projects.begin(), projects.end(), [](Project &a, Project &b) {
        return a.start < b.start;
    });
    for (int i = 0; i < n; i++) {
        starts.push_back(projects[i].start);
    }
    dp.assign(n, -1);
    cout << f(0) << endl;
    return 0;
}