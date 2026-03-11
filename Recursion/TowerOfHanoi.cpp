#include<bits/stdc++.h>
using namespace std;
void towerH(int n,char a, char b, char c){
    if(n==0) return;
    towerH(n-1,a,c,b);
    cout<<a<<" -> "<<c<<endl;
    towerH(n-1,b,a,c);
}
int main(){
    int n;
    cin>>n;
    towerH(n,'A','B','C');
}