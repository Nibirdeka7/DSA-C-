#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum =(n*(n+1))/2;
    long long target = sum/2;
    vector<int>a, b;
    if(sum%2 != 0){
        cout << "NO";
    } else {
        cout << "YES" << endl;
        for(int i = n; i >= 1; i--){
            if(target >= i){
                a.push_back(i);
                target -= i;
            } else {
                b.push_back(i);
            }
        }
        cout << a.size() << endl;
        for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << endl << b.size() << endl;
        for(int i = 0; i < b.size(); i++) cout << b[i] << " ";
    }

}