#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    vector<int>vis(n+1, 0);
    vector<int>dis(n+1, INT_MAX);
    q.push(1);
    dis[1] = 1;
    vis[1] = 1;
    vector<int>path(n+1);
    for(int i = 0; i <= n; i++) path[i] = i;
    while(!q.empty()){
        int node = q.front();
        vis[node] = 1;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it] && 1 + dis[node] < dis[it]){
                path[it] = node;
                dis[it] = 1 + dis[node];
                q.push(it);
            }
        }
    }
    if(dis[n] == INT_MAX){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dis[n] << endl; 
        int i = n;
        vector<int>ans;
        ans.push_back(i);
        while(path[i] != i){
            i = path[i];
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    }
}