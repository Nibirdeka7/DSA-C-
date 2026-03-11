#include<bits/stdc++.h>
#define pp pair<int,int>

using namespace std;
vector<list<pair<int,int>> > graph;
void add_edge(int src, int dest,int w, bool bi_dir = true){
    graph[src].push_back({dest,w});
    if(bi_dir){
        graph[dest].push_back({src,w});
    }
}


long long prims(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    unordered_set<int> vis;
    vector<int>par(n+1);
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++) mp[i] = INT_MAX;
    pq.push({0,src});
    mp[src] = 0;
    int total_count = 0, result = 0;
    while(total_count < n&& !pq.empty()){  
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for(auto neighbour : graph[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first] > neighbour.second){
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}


int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n+1, list<pair<int,int> >());
    while(m--){
        int s, d, w;
        cin >> s >> d >> w;
        add_edge(s, d, true);
    }
}