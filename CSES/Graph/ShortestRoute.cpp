#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long,long long>>>adj(n+1);
    while(m--){
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<long long>dis(n+1, LLONG_MAX);
    dis[1] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        long long d = node.first;
        long long u = node.second;
        if (d > dis[u])
            continue;
        for(auto neigh : adj[u]){
            long long v = neigh.first;
            long long w = neigh.second;

            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }   

}