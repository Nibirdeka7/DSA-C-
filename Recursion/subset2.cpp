// with duplicate elements
#include<bits/stdc++.h>
using namespace std;
void subset(string ans,string s,bool flag,vector<string>&v){
    if(s==""){
        v.push_back(ans);
        return;
    }
    char ch=s[0];
    if(s.length()==1){
        if(flag==true) subset(ans+ch,s.substr(1),true,v);
        subset(ans,s.substr(1),false,v);
        return;
    }
    char dh=s[1];
    if(ch==dh){
        if(flag==true) subset(ans+ch,s.substr(1),true,v);
        subset(ans,s.substr(1),false,v);
    }
    else{
        if(flag==true) subset(ans+ch,s.substr(1),true,v);
        subset(ans,s.substr(1),true,v);
    }
}
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string>v;
    subset("",s,true,v);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
}