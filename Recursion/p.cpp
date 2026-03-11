#include<bits/stdc++.h>
using namespace std;
int c(int m){
    if(m<=2) return m;
    return c(m-1)+c(m-2);
}
int main(){
    int n;
    cin>>n;
    cout<<c(n);
}