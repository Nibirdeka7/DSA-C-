#include<bits/stdc++.h>
using namespace std;
int grid[4][4]={};
int f( int curr, int mask, int n){
    if( curr == (1<<n)-1 ){
        return grid[curr][0];

    }
    int ans = INT_MIN;

    for(int neigh = 0; neigh < n; neigh++){
        if( mask & (1<<neigh) == 0){
            ans = min( ans, grid[curr][neigh] + f(neigh, mask | (1<<neigh), n));
        }
    }
}
int main() {
    
}