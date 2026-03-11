#include<bits/stdc++.h>
using namespace std;
void parenth(string ans,int o,int c,int n){
    if(c==n){
        cout<<ans<<endl;
        return;
    }
    if(o<n){
    parenth(ans+'(',o+1, c, n);
    }
    if(c<o){
    parenth(ans+')',o, c+1, n);
}
}
int main(){
    string s;
    int n;
    cin>>n;
    parenth(s,0,0,n);
}