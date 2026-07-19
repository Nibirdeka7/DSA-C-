#include<bits/stdc++.h>
using namespace std;
string ans = "";
bool found;
int n, m;
void dfs(int i, int j, vector<vector<char>>&a, string s){
    if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '#' || a[i][j] == 'M') return;
    if((i == 0 || j == 0 || i == n-1 || j == m-1) && a[i][j] == '.'){
        ans = s;
        found = true;
        return;
    }
    a[i][j] = '#';
    dfs(i, j-1, a, s+'L');
    dfs(i, j+1, a, s+'R');
    dfs(i-1, j, a, s+'U');
    dfs(i+1, j, a, s+'D');
    
}
int main(){
    cin >> n >> m;
    vector<vector<char>>a(n, vector<char>(m));
    int start_i = -1, start_j = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                start_i = i;
                start_j = j;
            }
        }
    }
    dfs(start_i, start_j, a, "");
    if(found){
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans;
    } else {
        cout << "NO" << endl;
    }
}