// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

// Example 1:

// Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

//      0          3
//      |          |
//      1 --- 2    4

// Output: 2
// Example 2:

// Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

//      0           4
//      |           |
//      1 --- 2 --- 3

// Output:  1
// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


// i think this could be solved using DSU where i can use a set to store the parent unique numbers and later return that set size

#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void Union(vector<int>&parent,vector<int>&rank,int x, int y){
    x = find(parent, x);
    y = find(parent, y);
    if(x == y) return;
    if(rank[x] > rank[y]){
        parent[y] = x;
        rank[x]++;
    } else{
        parent[x] = y;
        rank[y]++;
    }
    return;

}

int numCC(vector<vector<int> >& edges, int v){
    
    vector<int> parent(v);
    vector<int> rank(v,0);
    for(int i = 0; i < v; i++) parent[i] = i;

    
    for(int i = 0; i < edges.size(); i++){
        Union(parent,rank,edges[i][0], edges[i][1]);
    }
    unordered_set<int> unique_parents;
    for(int i = 0; i < v; i++){
        unique_parents.insert(find(parent, i));
    }
    return unique_parents.size();
}
int main(){
    int v;
    cin >> v;
    vector<vector<int> >edges = {{0,1}, {1,2}, {3,4}};
    cout << numCC(edges, v);
    
}