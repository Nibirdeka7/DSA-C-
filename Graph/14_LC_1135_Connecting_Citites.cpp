// direct implementation of Kruskal Algo
// There are N cities numbered from 1 to N.

// You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

// Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int> parent, int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent,parent[x]);
}

void Union(vector<int>&parent, vector<int>& rank, int a, int b){
    a = find(parent,parent[a]);
    b = find(parent,parent[b]);
    if(a == b) return;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    } else{
        rank[b]++;
        parent[a] = b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};



bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}


ll kruskal(vector<Edge>&input, int n, int v){
    sort(input.begin(), input.end(), cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1,1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    int edgeCount = 0; // n-1 (for making a tree maximum edge can be n-1) n = no. of vertices
    int i = 0;
    int ans = 0;
    while(edgeCount < n-1 and i < input.size()) {
        Edge curr = input[i]; // as it is sorted we will get the min ones first
        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest);
        if(srcPar != destPar){
            // include that edge
            Union(parent, rank, srcPar, destPar);
            ans += curr.wt;
            edgeCount++;
        }
        i++;
    }
    set<int>s;
    for(int i = 1; i <= n; i++){
        s.insert(parent[i]); // checking if there's more than 1 connected component
        // cout << parent[i] << " ";
    }
    if(s.size()>1) return -1;
    else return ans;
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<Edge> v(n);
    for(int i = 0; i < e; i++){
        cin >> v[i].src >> v[i].dest >> v[i].wt;
    }
    cout << kruskal(v, n, e);
}