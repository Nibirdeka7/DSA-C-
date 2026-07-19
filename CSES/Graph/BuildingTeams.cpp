#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // 0 = unvisited, 1 = team1, 2 = team2
    vector<int> color(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neigh : adj[node]) {
                    if (color[neigh] == 0) {
                        color[neigh] = 3 - color[node];
                        q.push(neigh);
                    }
                    else if (color[neigh] == color[node]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}