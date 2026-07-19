#include<bits/stdc++.h>
using namespace std;

string ans = "";
bool found = false;

void dfs(int i, int j, vector<vector<char>>& v, string s){
    if(found) return;
    if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == '#')
        return;
    if(v[i][j] == 'B'){
        ans = s;
        found = true;
        return;
    }
    v[i][j] = '#';

    dfs(i-1, j, v, s+'U');
    dfs(i+1, j, v, s+'D');
    dfs(i, j+1, v, s+'R');
    dfs(i, j-1, v, s+'L');
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    int sx, sy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'A'){
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx, sy, v, "");
    if(found){
        cout << "YES\n";
        cout << ans.length() << "\n";
        cout << ans;
    }
    else{
        cout << "NO";
    }
}