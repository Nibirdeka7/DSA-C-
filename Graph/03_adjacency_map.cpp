// unweighted adjacency_map
#include<bits/stdc++.h>
using namespace std;
vector<unordered_map<int,int> >  graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src][dest] = 1;
    if(bi_dir){
        graph[dest][src] = 1;
    }

}
void display(){
    for(int i = 0; i<graph.size(); i++){
        cout << i << "->";
        for(auto el : graph[i]){
            cout << "(" << el.first<<" "<<el.second << ") ,";
        }
        cout << endl;
    }
}

int main(){

    cin >> v;
    graph.resize(v,unordered_map<int,int>());
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;

        add_edge(s,d); // undirected
        // add_edge(s,d,false); // directional
    }
    display(); 
}