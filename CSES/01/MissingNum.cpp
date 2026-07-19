#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<int>a(n-1);
    vector<int>f(n+1, 0);
    for(int i = 0; i < n-1; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        f[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            cout << i << endl;
            break;
        }
        
    }

}