#include<bits/stdc++.h>
using namespace std;
void foo(int n){
    if(n > 0){
        cout << n << " ";
        foo(n-1);
        foo(n-1);
    }
}
int main(){
    foo(4);
}