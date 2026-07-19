#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, parent;
int startNode = -1, endNode = -1;

bool dfs(int node, int par){

    vis[node] = 1;

    for(auto neigh : adj[node]){

        if(neigh == par) continue;

        if(vis[neigh]){
            startNode = neigh;
            endNode = node;
            return true;
        }

        parent[neigh] = node;

        if(dfs(neigh, node))
            return true;
    }

    return false;
}

int main(){

    int n,m;
    cin >> n >> m;

    adj.resize(n+1);
    vis.resize(n+1,0);
    parent.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool found = false;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                found = true;
                break;
            }
        }
    }

    if(!found){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(startNode);

    int cur = endNode;
    while(cur != startNode){
        cycle.push_back(cur);
        cur = parent[cur];
    }

    cycle.push_back(startNode);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for(auto x : cycle)
        cout << x << " ";
}