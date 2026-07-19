#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int>vis;
vector<vector<int>> result;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
bool dfs(int curr, int end, vector<int>&path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    vis.insert(curr);
    path.push_back(curr);
    for(auto neigh : graph[curr]){
        if(!vis.count(neigh)){
            dfs(neigh, end, path);
        }
    }
    path.pop_back();
    vis.erase(curr);
    return;
}
bool allPath(int x, int y){
    vector<int>v;
    return dfs(x,y,v);
}

void bfs(int src, vector<int>&dist){
    vis.clear();
    queue<int>q;
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    vis.insert(src);

    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neigh : graph[curr]){
            if(!vis.count(neigh)){
                q.push(neigh);
                vis.insert(neigh);
                dist[neigh] = dist[curr]+1;
            }
        }
    }
}
void topo_bfs(){
    vector<int> indegree(v);
    for(int i = 0; i < v; i++){
        for(auto neigh : graph[i]){
            indegree[neigh]++;
        }
    }
    queue<int>q;
    unordered_set<int>vis;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
            vis.insert(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto neigh : graph[node]){
            if(!vis.count(neigh)){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                    vis.insert(neigh);
                }
            }
        }
    }
}
int main(){
    cin >> v;
    graph.resize(v, list<int>());
    vis.clear();
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s,d);
    }
    int x, y;
    cin >> x >> y;
    cout << allPath(x,y);
}