#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>>dis(n+1, vector<long long>(n+1, LLONG_MAX));
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], (long long)c);
        dis[b][a] = min(dis[b][a], (long long)c);
    }
    for(int i = 0; i <= n; i++) dis[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dis[i][k] != LLONG_MAX && dis[k][j]!= LLONG_MAX )
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    vector<long long>ans;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(dis[a][b] != LLONG_MAX){
            ans.push_back(dis[a][b]);
        } else {
            ans.push_back(-1);
        }
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}