#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    reverse(s.begin()+n/2,s.end());
    cout<<s;

}