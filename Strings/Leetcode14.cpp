#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>s={"flower","flow","flight"};
    int n=s.size();
    if(n==1) cout<<s[0];
    sort(s.begin(),s.end());
    string first = s[0];
    string last = s[n-1];
    string p= "";
    for(int i=0;i<(min(first.size(),last.size()));i++){
        if(first[i]==last[i]){
        p+=first[i];
        }
        else break;

    }
    cout<<p;
}