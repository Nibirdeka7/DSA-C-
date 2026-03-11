#include<bits/stdc++.h>
using namespace std;
int check(string tmp){
    int mxL=0,n=tmp.size();
    string str=tmp;
    sort(tmp.begin(),tmp.end());
    if(str==tmp){
        mxL=n;
    }
    return mxL;
}
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string tmp;
    int ans;
    while(ss>>tmp){
        ans=check(tmp);
        
    }
}