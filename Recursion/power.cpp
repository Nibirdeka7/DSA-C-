#include<bits/stdc++.h>
using namespace std;
int powerr(int a,int b){
    if(b==0) return 1;
    return a*powerr(a,b-1);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<powerr(a,b);
}