#include<bits/stdc++.h>
using namespace std;
vector<list<int> > graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }

}
void display(){
    for(int i = 0; i<graph.size(); i++){
        cout << i << "->";
        for(auto el : graph[i]){
            cout << el <<",";
        }
        cout << endl;
    }
}
void topo_bfs(){
    vector<int>indegree(v);

    for(int i = 0; i < v; i++){
        for(auto neighbour : graph[i]) {
            indegree[neighbour]++;
        }
    }
    queue<int>q;
    unordered_set<int> vis;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
            vis.insert(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for(auto neighbour : graph[node]){
            if(not vis.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                     q.push(neighbour);
                     vis.insert(neighbour);
                }
            }
        }
    }
}
int main(){
     cin >> v;
    graph.resize(v, list<int>());
    int e; 
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d; // source and destination
        add_edge(s,d,false); // directional
    }
    topo_bfs();
}