#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> parent, sz;

    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1,1);

        for(int i=1;i<=n;i++)
            parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
};

int main(){

    int n,m;
    cin>>n>>m;

    DSU dsu(n);

    while(m--){
        int a,b;
        cin>>a>>b;
        dsu.unite(a,b);
    }
    vector<int> comps;

    for(int i=1;i<=n;i++){
        if(dsu.find(i)==i){
            comps.push_back(i);
        }
    }
    cout<<comps.size()-1<<endl;
    for(int i=1;i<comps.size();i++){
        cout<<comps[i-1]<<" "<<comps[i]<<endl;
    }
}