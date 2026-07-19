#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v;
    long long w;
};

int main(){
    int n,m;
    cin>>n>>m;

    vector<Edge> edges;

    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vector<long long> dis(n+1,0);
    vector<int> par(n+1,-1);

    int x=-1;

    for(int i=0;i<n;i++){
        x=-1;
        for(auto e:edges){
            if(dis[e.u]+e.w<dis[e.v]){
                dis[e.v]=dis[e.u]+e.w;
                par[e.v]=e.u;
                x=e.v;
            }
        }
    }

    if(x==-1){
        cout<<"NO\n";
        return 0;
    }

    for(int i=0;i<n;i++)
        x=par[x];

    vector<int> cycle;

    int cur=x;
    do{
        cycle.push_back(cur);
        cur=par[cur];
    }while(cur!=x);

    cycle.push_back(x);

    reverse(cycle.begin(),cycle.end());

    cout<<"YES\n";
    for(int v:cycle)
        cout<<v<<" ";

    cout<<"\n";
}