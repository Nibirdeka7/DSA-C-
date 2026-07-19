#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }

    // print evens
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    }

    // print odds
    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }

    return 0;
}