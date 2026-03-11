#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}

void Union(vector<int>&parent,vector<int>&sz, vector<int>&minimal,vector<int>&maximal, vector<int>&rank, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if(x == y) return;
    if(rank[x] > rank[y]) {
        parent[y] = x;
        rank[x]++; 
        sz[x] += sz[y];
        maximal[x] = max(maximal[x], maximal[y]); 
        minimal[x] = max(minimal[x], minimal[y]); 

    } else {
        parent[x] = y;
        rank[y]++;
        sz[y] += sz[x];
        maximal[y] = max(maximal[x], maximal[y]); 
        minimal[y] = max(minimal[x], minimal[y]); 
    }
}

int main(){
    int n, m;
    cin >> n;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    vector<int> sz(n+1,1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    for (int i = 0; i <= n; i++) {
        parent[i] = minimal[i] = maximal[i] = i;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        Union(parent, sz, minimal, maximal, rank, x, y);
    }
    
}