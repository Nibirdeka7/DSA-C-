#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int> > result;
int v;
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void bfs(int src, vector<int>& dist) {
    visited.clear();
    queue<int> q;
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);

    q.push(src);
    while(!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(auto neighbour : graph[curr]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}
int main(){
    cin >> v;
    graph.resize(v, list<int>());
    visited.clear();
    vector<int>dist;
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    int x,y;
    cin >> x;

    cout << endl << "Travelling immediate neighbours as" << endl;
    bfs(x,dist);
    cout << endl;
    cout << endl << "Shortest Disatance is -> " ;
    for(int i = 0 ; i < v; i++){
        cout << dist[i] << " ";
    }
}