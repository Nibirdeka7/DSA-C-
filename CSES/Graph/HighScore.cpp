#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<vector<int>> rev(n+1);
    vector<long long>dis(n+1, LLONG_MAX);
    dis[1] = 0;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, -c});
        rev[b].push_back(a);
    }
    for(int i = 1; i < n; i++){
        for(int u = 1; u <= n; u++){
            for(auto neigh : adj[u]){
                int v = neigh.first;
                int w = neigh.second;
                if(dis[u] != LLONG_MAX && dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }

        }
    }
    vector<int>bad(n+1, 0);
    for(int u = 1; u <= n; u++){
       for(auto neigh : adj[u]){
           int v = neigh.first;
             int w = neigh.second;
                if(dis[u] != LLONG_MAX && dis[u] + w < dis[v]){
                    bad[v] = 1;
                }   
            }

        }  
        
    vector<int>vis(n+1, 0);
    vis[n] = 1;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : rev[u]){
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }   
    }

    for(int i= 1; i <= n; i++){
        if(vis[i] && bad[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << -dis[n];

}
