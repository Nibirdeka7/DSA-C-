#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>adj(n+1);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({1, -1});
    vector<int>dis(n+1, INT_MAX);
    dis[1] = 1;
    vector<int>vis(n+1, 0);
    vis[1] = 1;
    vector<int>path(n+1);
    for(int i = 1; i <= n; i++) path[i] = i;
    while(!pq.empty()){
        auto node = pq.top();
        int u = node.first;
        int wt = node.second;
        for(auto it : adj[u]){
            if(!vis[it.first] && wt + dis[u] < dis[it.first]){
                dis[it.first] = wt + dis[u];
                vis[it.first] = 1;
                pq.push({it.first, u});
                path[it.first] = u;
            }
        }
    }

    int p = n;
    vector<int>ans;
    while(path[p] != p){
        ans.push_back(dis[p]);
        p = path[p];
    }
    sort(ans.begin(), ans.end());
    int fans = 0;
    for(int i =0;i < ans.size()-1; i++){
        fans += ans[i];
    }
    fans += ans[ans.size()-1]/2;
    cout << fans << endl;

}