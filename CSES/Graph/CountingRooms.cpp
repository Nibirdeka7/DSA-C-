#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>d = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
void dfs(int i, int j, vector<vector<char>>&v){
    if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == '#') return;
    v[i][j] = '#';
    for(auto it: d){
        dfs(i+it.first, j + it.second, v);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>>v(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] != '#'){
                ans++;
                dfs(i, j, v);
            }
        }
    }
    cout << ans;
}