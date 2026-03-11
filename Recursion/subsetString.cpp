#include<bits/stdc++.h>
using namespace std;
void subset(string ans,string s){
    if(s==""){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    subset(ans,s.substr(1));
    subset(ans+ch,s.substr(1));
}
int main(){
    string s;
    cin>>s;
    subset("",s);
}