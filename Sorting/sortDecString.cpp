#include<bits/stdc++.h>
using namespace std;
int main(){
    string str="AHJEFUHKCJADXWYXWI";
    string s="";
    for(int i=0;i<str.length();i++){
        if(str[i]>='X') s+=str[i];
    }
    cout<<s<<endl;
    sort(s.begin(),s.end());
    cout<<s<<endl;
}