#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> shops;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        shops.push_back(x);
    }

    vector<vector<int>> adj(n+1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dis(n+1, INT_MAX);
    queue<int> q;

    // Push all shops first
    for(auto shop : shops) {
        q.push(shop);
        dis[shop] = 0;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
}