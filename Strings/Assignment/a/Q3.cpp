#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int foo=1;
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) foo=0;
    }  
    if(foo==0) cout<<"Not Pallindrome" ;
    else cout<<"Yes";
}