#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}

bool Union(vector<int>&parent, vector<int>&rank, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if(x == y) return true;
    if(rank[x] >= rank[y]) {
        parent[y] = x;
        rank[x]++; 
    } else {
        parent[x] = y;
        rank[y]++;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        bool b = Union(parent, rank, x, y);
        if(b == true){
            cout << "Cycle Detected\n";
        }
    }
}