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
void dfs (int curr, int end, vector<int>&path){
    if( curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
     path.push_back(curr);
    for(auto neighbour : graph[curr]) {
        if(! visited.count(neighbour)){    // visited.count will return 1 if current is present
            dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr); // since it may be used in another path
    return;
}
void allPath(int src, int dest) {
    vector<int>v;
    dfs(src, dest, v);
}
int main(){
    cin >> v;
    graph.resize(v, list<int>());
    visited.clear();
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    int x,y;
    cin >> x >> y;
    allPath(x, y);
    for(auto path : result){
        for(auto el: path){
            cout << el << " ";
        }
        cout << endl;

    }

}