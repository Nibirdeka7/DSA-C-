#include<bits/stdc++.h>
using namespace std;
int ans ;
bool canWeGo(int i, int j, int n, vector<vector<int> > &grid){
    return i>=0 && j>=0 && i<n && j<n && grid[i][j] == 0;
}
void f( vector<vector<int> > &grid, int n, int i, int j ){
    if(i==n-1 && j==n-1){
        ans += 1;
        return;
    }

    grid[i][j] = 2; // visited marking
    // left
    if(canWeGo(i,j-1,n,grid)){
        f(grid, n, i, j-1);
    }
    // up
    if(canWeGo(i-1,j,n,grid)){
        f(grid, n, i-1, j);
    }
    // right
    if(canWeGo(i,j+1,n,grid)){
        f(grid, n, i, j+1);
    }
    // dowm
    if(canWeGo(i+1,j,n,grid)){
        f(grid, n, i+1, j);
    }

    grid[i][j]=0; // revert
}
int main(){
    vector<vector<int> > grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
   // ans = 0;
    f(grid,0,0,7);
    cout << ans << endl;

}