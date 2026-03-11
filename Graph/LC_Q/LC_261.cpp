// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// Example 1:

// Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
// Output: true
// Example 2:

// Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
// Output: false
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

// i think this a question of cycle detection
// and i am thinking to use DSU at first
#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x){
    if(parent[x] == x){
        return x;
    } 
    return parent[x] = find(parent,parent[x]);

}
bool Union(vector<int> &parent, vector<int> &rank, int x, int y){
    x = find(parent, x);
    y = find(parent, y);
    if(x == y) return true;
    if(rank[x] > rank[y]){
        parent[y] = x;
        rank[x]++;
    } else{
        parent[x] = y;
        rank[y]++;
    }
    return false;
}

bool isCycle(vector<vector<int> > &edges){
    int maxNode = 0;
    for(auto e: edges){
        maxNode = max({maxNode, e[0], e[1]});
    }
    int n = maxNode + 1;
    // cout << n;
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i = 0; i < n; i++) parent[i] = i;

    
    for(int i = 0; i < edges.size(); i++){
        bool b = Union(parent,rank,edges[i][0], edges[i][1]);
        if(b) return true;

    }
    return false;
}

// bool bfs(){
//     queue<int>q;
//     unordered_set<int> vis;
//     vector<int>parent(n,-1);
// }
int main(){
    vector<vector<int> > edges = {{0,1}, {0,2}, {0,3}, {1,4}};
    // DSU --->  
    cout << isCycle(edges);


    // ------------- bfs cycle detection ------------
    // IF a parrticular node is visited and its not the parent of the curr node then cycle is detected


}