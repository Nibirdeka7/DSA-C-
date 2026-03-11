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
// if(vis.count(neighbour) and neighbour != parent){
//             // cycle detected
//             return true;
//         }

bool bfs(int src) {
    unordered_set<int> vis;
    vector<int> parent(v,-1);
    queue<int>q;
    q.push(src);
    vis.insert(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour : graph[curr]){
            if(vis.count(neighbour) and neighbour != parent[curr]){
//             // cycle detected
                return true;
            }
            if(!vis.count(neighbour)){
                vis.insert(neighbour);
                parent[neighbour] = curr;
                q.push(neighbour);
            }
        }
    }
    
}

bool has_cycle(){
    unordered_set<int>vis;
    for(int i = 0; i < v; i++){
        if(!vis.count(i)){
            bool result = bfs(i);
            if(result == true) return true;
        }
    }
    return false;
}

int main(){

    cin >> v;
    graph.resize(v, list<int>());
    int e; 
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d; // source and destination

        add_edge(s,d); // undirected
        // add_edge(s,d,false); // directional
    }
    display(); 
}