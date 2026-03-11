#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pair<int,int >> > gr;
void add_edge(int u, int v, int wt, bool bi_dir = true) {
    gr[u].push_back({v,wt});
    if(bi_dir){
        gr[v].push_back({u,wt});
    }
}

unordered_map<int,int> djikstra(int src, int n){ // total TC : O(VlogV + ElogV)
    priority_queue<pp, vector<pp>, greater<pp> > pq; // {dist, node}
    unordered_set<int>vis;
    vector<int> via(n+1);
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) { //  1 based indexing
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    while(!pq.empty()){ // O((V+E)logV)    , as theres ops in pq hence logV
        pp curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour : gr[curr.second]) { // O(V+E) , since this part is similar to BFS
            if(! vis.count(neighbour.first) and mp[neighbour.first] > mp[curr.second] + neighbour.second) {// neighbour.first --> as in the graph pair is {v,wt}
                pq.push({mp[curr.second] + neighbour.second,neighbour.first});
                via[neighbour.first] = curr.second; // updating the parent
                mp[neighbour.first] = mp[curr.second] + neighbour.second; // updating the wt in map
            }
        }
    }
    return mp;

}

int main(){
    int n, m;
    cin >> n >> m;
    gr.resize(n, list<pair<int, int >> ());
    while(m--){
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u,v,wt);
        
    }
    int src;
    cin >> src;
    unordered_map<int,int>  sp = djikstra(src, n);
    for(auto p : sp){
        cout << p.first << " " << p.second << endl;
    }
    // int dest;
    // cin >> dest;
    // cout << sp[dest] << endl;

}